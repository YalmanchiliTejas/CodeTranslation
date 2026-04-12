#include<cstdio>
#include<string.h>

using namespace std;

int main(void){
  char dir[256];
  char tmp;
  int n,x,i,j;
	
  scanf("%d",&n);
	
  char color[n][1000];
	
  memset(color,'\0',sizeof(color));
  memset(dir,'\0',sizeof(dir));
	
  while(1){
    scanf("%s",dir);
		
    if(!strcmp(dir,"quit")){
      break;
    }else if(!strcmp(dir,"push")){
      scanf(" %d",&n);
      for(i=0;color[n-1][i]!='\0';i++);
      scanf(" %c",&color[n-1][i]);
    }else if(!strcmp(dir,"pop")){
      scanf(" %d",&n);
      for(i=0;color[n-1][i]!='\0';i++);
      printf("%c\n",color[n-1][i-1]);
      color[n-1][i-1] = '\0';
    }else if(!strcmp(dir,"move")){
      scanf(" %d %d",&n,&x);
      for(i=0;color[n-1][i]!='\0';i++);
      for(j=0;color[x-1][j]!='\0';j++);
      color[x-1][j] = color[n-1][i-1];
      color[n-1][i-1] = '\0';
    }
		
    memset(dir,'\0',sizeof(dir));
		
  }
	
  return 0;
	
}