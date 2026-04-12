#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i,k,N,max,sum;
  scanf("%d\n",&N);
  vector<int> a(N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  max=a[0];
  sum=1;
  for(k=0;k<N-1;k++){
    if(max<=a[k+1]){
      sum++;
      max=a[k+1];
    }
  }
  printf("%d",sum);
  return 0;
}
