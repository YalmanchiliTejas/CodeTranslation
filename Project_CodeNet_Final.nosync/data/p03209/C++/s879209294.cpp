#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef long long Int;
typedef pair<Int,Int> P;
Int s[55]={0};
Int memo[55];
void set_size(Int n){
  for(Int i=0;i<n;i++){
    s[i+1]=s[i]*(Int)2+(Int)3;
    memo[i]=0;
  }
}
Int get_ba(Int n,Int k){
  if(n==0) return 1;
  if(memo[n]!=0&&k==s[n]) return memo[n];
  Int mid=(s[n]+1)/2;
  Int ret=0;
  if(mid>k&&k>1) ret=get_ba(n-1,k-1);
  if(mid==k) ret=get_ba(n-1,mid-2)+(Int)1;
  if(mid<k) ret=get_ba(n-1,mid-2)+(Int)1+get_ba(n-1,min(k,s[n]-1)-mid);
  if(k==s[n]) memo[n]=ret;
  return ret;
}
int main(){
  Int n,x;
  cin>>n>>x;
  s[0]=1;
  set_size(n);
  cout<<get_ba(n,x)<<endl;
}
