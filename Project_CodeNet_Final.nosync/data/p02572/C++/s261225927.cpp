#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define mod (1000000007)
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<long long>A(N);
  long long ans=0;
  long long allsum=0;
  for(int i=0;i<=N-1;i++){
  
    cin>>A[i];
    allsum+=A[i];
    allsum%=mod;
  }
  for(int i=0;i<=N-2;i++){
  
    allsum-=A[i];
    if(allsum<0)allsum+=mod;
    ans+=allsum*A[i];
    ans%=mod;
  }
  cout<<ans;
  return 0;
}