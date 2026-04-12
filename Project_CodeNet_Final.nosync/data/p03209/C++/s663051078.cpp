#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_lld(const void *a, const void *b)
{
  long long int *A = (long long int *)a;
  long long int *B = (long long int *)b;
  if (*A > *B) return 1;
  if (*A < *B) return -1;
  return 0;
}

int main(){
  long long int n,x,i;
  scanf("%lld",&n);
  scanf("%lld",&x);
  long long int total[51];
  total[0] = 1;
  for(i=1;i<51;i++){
    total[i] = total[i-1]*2+3;
  //  printf("%lld\n",total[i]);
  }
  long long int ntemp,xtemp,ans;
  long long int end = 0;
  ntemp = n;
  xtemp = x;
  ans = 0;
  while(ntemp > 0 && end == 0) {
    //printf("%lld %lld %lld\n",ntemp,xtemp,ans);
    if (xtemp == 0) {
      end = 1;
    } else if (xtemp == 1) {
      end = 1;
      xtemp = 0;
    } else if (xtemp < (total[ntemp]+1)/2) {
      xtemp -= 1;
    } else if (xtemp == (total[ntemp]+1)/2) {
      ans += (total[ntemp-1]+1)/2 + 1;
      end = 1;
    } else if (xtemp < total[ntemp]) {
      ans += (total[ntemp-1]+1)/2 + 1;
      xtemp -= (total[ntemp]+1)/2;
    } else {
      ans += (total[ntemp]+1)/2;
      end = 1;
    }
    ntemp--;
  }
  if(ntemp == 0 && xtemp == 1) {
    ans++;
  }
  printf("%lld\n",ans);
  return 0;
}
