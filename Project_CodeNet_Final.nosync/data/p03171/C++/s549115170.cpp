#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long

#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define repA(i,A)   for(auto i:A)

#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl

#define mp make_pair
#define pb push_back
#define all(A)  A.begin(),A.end()
#define ft first
#define sd second

#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>

#define endl "\n"

const ll logN = 20;
const ll N = 100005;
const ll M = 1000000007;
#define PI 3.14159265

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i, 0, n) cin>>a[i];
  ll dp[n+3][n+3];
  repb(l, n-1, 0){
    rep(r, l, n){
      if(l == r) dp[l][r] = a[l];
      else
      dp[l][r] = max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
//      cout<<dp[l][r]<<" ";
    }
//    cout<<endl;
  }
  cout<<dp[0][n-1];
  return 0;
}
