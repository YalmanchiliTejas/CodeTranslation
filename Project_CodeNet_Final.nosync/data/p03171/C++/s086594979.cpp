//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
ll flag[3010][3010];
ll dp[3010][3010];
ll a[3010];
ll f(ll l,ll r){
  if(flag[l][r])return dp[l][r];
  flag[l][r]=1;
  if(l==r)return dp[l][r]=a[l-1];
  return dp[l][r]=max(a[l-1]-f(l+1,r),a[r-1]-f(l,r-1));
}
int main(){
  ll n;cin>>n;
  rep(i,n)cin>>a[i];
  cout<<f(1,n)<<endl;
}