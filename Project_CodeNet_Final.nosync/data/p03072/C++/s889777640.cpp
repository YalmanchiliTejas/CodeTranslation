#include <stdio.h>

int main(void){
  int n;
  scanf("%d", &n);
  int h[n];
  for(int i = 0;i < n;i++){
	scanf(" %d", &h[i]);
  }
  int r = 1;
  for(int i = 1;i < n;i++){
	for(int j = 0;j < i;j++){
	  if(h[i] >= h[j]){
		if(j == i - 1){
		  r++;
		}else{
		  continue;
		}
	  }else{
		break;
	  }
	}
  }
  printf("%d\n", r);
}
