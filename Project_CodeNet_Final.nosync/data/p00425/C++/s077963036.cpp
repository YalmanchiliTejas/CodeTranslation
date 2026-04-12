#include <cstdio>
#include <cstring>
int main(void)
{
  while(1){
    int n;
    scanf("%d",&n);
    if(!n) break;
    int t=1,f=2,r=3;
    int res = 1;
    char str[10];
    int temp;
    for(int i=0;i<n;i++){
      scanf("%s",str);
      if(str[0] == 'N'){
	temp = f;
	f = 7 - t;
	t = temp;
      }else if(str[0] == 'E'){
	temp = t;
	t = 7 - r;
	r = temp;
      }else if(str[0] == 'W'){
	temp = r;
	r = 7 - t;
	t = temp; 
      }else if(str[0] == 'S'){
	temp = t;
	t = 7 - f;
	f = temp;
      }else if(str[0] == 'R'){
	temp = r;
	r = 7 - f;
	f = temp;
      }else{
	temp = f;
	f = 7 - r;
	r = temp;
      }
      res += t;
    }
    printf("%d\n",res);
  }
}