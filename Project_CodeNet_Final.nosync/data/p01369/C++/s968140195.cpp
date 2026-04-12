#include <stdio.h>
int main(){

  int ans=0,i,r=0,l=0; 

  char c;

  for(;;){
    for(;;){

      scanf("%c",&c);

      if(c=='#'){
	break;
      }

      if(c=='\n'){
	break;
      }

      if(c=='q'||c=='w'||c=='e'||c=='r'||c=='t'||c=='a'||c=='s'||
	 c=='d'||c=='f'||c=='g'||c=='z'||c=='x'||c=='c'||c=='v'||c=='b'){

	l=1;
	if(l==1&&r==1){
	  ans++;
	}

	r=0;
      }

      else{

	r=1;
	if(l==1&&r==1){
	  ans++;
	}

	l=0;
      }
    }
  if(c=='#'){
	break;
      }


    printf("%d\n",ans);
    ans=0;
    r=0;
    l=0;
  }
    return 0;
  }