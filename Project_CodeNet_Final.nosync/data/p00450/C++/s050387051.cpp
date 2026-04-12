#include <stdio.h>
#include <string.h>
int m[100000][2];
int main(){
  int n,i,j,t;
  for(;;){
    scanf("%d",&n);
    if(n==0) break;
    memset(m,-1,sizeof(m));
    t = 0;
    for(i=1;i<=n;i++){
      scanf("%d",&j);
      if(i % 2 == 1){
	if(m[t][1] == -1){
	  m[t][1] = j;
	  m[t][0] = 1;
	}else if(m[t][1] == j){
	  m[t][0]++;
	}else{
	  m[++t][1] = j;
	  m[t][0] = 1;
	}
      }else{
	if(m[t][1] == j){
	  m[t][0]++;
	}else{
	  if(t == 0){
	    m[t][1] = j;
	    m[t][0]++;
	  }else{
	    m[t-1][0] += m[t][0] + 1;
	    t--;
	  }
	}
      }
    }
    j = 0;
    while(t>=0){
      if(m[t][1] == 0) j += m[t][0];
      t--;
    }
    printf("%d\n",j);
  }
  return 0;
}