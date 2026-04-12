#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int64_t>a(N);
  for(int i=0;i<N;i++)
    cin>>a.at(i);
  int64_t left=-1;
  int64_t right=1000000000000000000;
  while(1<right-left){
  int64_t mid=left+(right-left)/2;
    int64_t b=0;
    for(int i=0;i<N;i++){
      b+=(mid+a.at(i)+1)/(N+1);
    }if(b<=mid)
      right=mid;
    else
      left=mid;
  }int64_t ans=right;
  for(int i=0;i<=N*N;i++){
  if(0<=right-i){
  int64_t r=right-i;
    int64_t b=0;
    for(int j=0;j<N;j++)
      b+=(r+a.at(j)+1)/(N+1);
    if(b<=r)
      ans=r;
  }
  }cout<<ans<<endl;
  return 0;
}