#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
bool judge(vector<int> const& a,int n){
  bool flag=false;
  rep(i,n){
    if(a[i]>=n){
      flag=true;
      break;
    }
  }
  return flag;
}
int calc(vector<int>& a,int n){
  int res=0;
  rep(i,n){
    int buf=a[i]/n;
    a[i]%=n;
    res+=buf;
    rep(j,n){
      if(i==j)continue;
      else{
        a[j]+=buf;
      }
    }
  }
  return res;
}
signed main(){
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n){
    cin>>a[i];
  }
  int res=0;
  while(judge(a,n)){
    res+=calc(a,n);
  }
  cout<<res<<endl;
  return 0;
}
