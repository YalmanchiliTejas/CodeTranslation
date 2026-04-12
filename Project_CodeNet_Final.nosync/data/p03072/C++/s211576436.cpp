#include <stdio.h>
int main(){
  int t, a[100], i=0, cont=1, nve;

  scanf("%d", &t);

  while(t--){
    scanf("%d", &a[i]);
    i++;
  }

  for(int k=i-1, c=i-2; k>=1; k--, c--){
    nve=0;
          for(int j=k; j>=0 ; j--){

              if( (a[k] < a[j]) && (k!=j)){
                  nve=1;}
            }

          if(nve!=1)
              cont++;
  }

  printf("%d\n", cont);

  return 0;
}
