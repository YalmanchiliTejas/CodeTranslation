#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[55],ans,step;

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
  while(true){
    int flag = 0;
    for(int i=0;i<n;i++){
      long long tmp = arr[i]/n;
      arr[i]-=tmp*n;
      ans+=tmp;
      if(tmp>0) flag=1;
      else continue;
      for(int j=0;j<n;j++){
        if(i==j) continue;
        arr[j]+=tmp;
        step++;
      }
    }
    if(!flag) break;
  }
  printf("%lld",ans);
}