/*Implement setenv & unsetenv with putenv e getenv
unsetenv should remove all the env with the same name
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern char **environ;

char *_setenv(const char *name,const char *value,int overwrite);
int _unsetenv(const char *name);

int main(int argc,const char **argv){
	char *debug = _setenv("Hello","World",0);
  	
	//for(char **p = environ;*p != NULL;p++)puts(*p);
  	//printf("DEbug %d",debug);
  	_unsetenv("SHELL");
	_unsetenv("LOGNAME");
  	for(char **p = environ;*p != NULL;p++){puts(*p);}
	free(debug);
  	return 0;
}

char *_setenv(const char *name,const char *value,int overwrite)
{

  	int length = strlen(name) + strlen(value);
  	char *string = malloc(sizeof(char)*length);
  	sprintf(string,"%s=%s",name,value);
  	char *env = NULL;
  	env = getenv(name);
  	if((env != NULL ) && !overwrite){
		return NULL;
	}else if((env != NULL) && overwrite){
    		env = value;
    		return env;
  	}else{
  		putenv(string);
  	}
  		return string;
}

int _unsetenv(const char *name){

  char *env = getenv(name);
  	if(env == NULL){
    		return 0;
  	}
  	int length = strlen(name) + strlen(env)+1;
  	char string[length];
  	char **p = environ;
  	char **temp = NULL;
  	sprintf(string,"%s=%s",name,env);
	int flag = 0;
  	for(p = environ;*p != NULL;p++){
    		temp = p+1; 
    		if(strcmp(*p,string) == 0 || flag){
      			flag = 1;
      			*p = NULL;
			*p = *temp;
			 
    		}
  	}
  
  
  return 0;
  
}
