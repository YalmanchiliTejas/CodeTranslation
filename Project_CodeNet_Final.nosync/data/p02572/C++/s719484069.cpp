#include <bits/stdc++.h>
using namespace std;
int main(){
  int64_t sum=0,count=0,N,i;
  cin>>N;
  int64_t A[N];
  for(i=0;i<N;i++){
    cin>>A[i];
  }
  for(i=0;i<N;i++){
    sum+=A[i];
    sum=sum%((int64_t)(1000000000+7));
  }
  for(i=0;i<N;i++){
    sum-=A[i];
    if(sum<0) sum+=1000000000+7;
    count+=((int64_t)(sum*A[i]))%((int64_t)(1000000000+7));
  }
  count=count%((int64_t)(1000000000+7));
  cout<<count<<endl;
}