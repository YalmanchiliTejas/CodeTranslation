//DPまとめ S Digit Sum
//https://atcoder.jp/contests/dp/tasks/dp_s
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<'\n';
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;

ll dp[10010][2][110];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int n=len(s);
    int d;
    cin>>d;
    dp[0][0][0]=1;
    rep(i,n)rep(j,2)rep(k,d){
      int x=s[i]-'0';
      for(int l=0;l<=(j?9:x);l++) (dp[i+1][j||l<x][(k+l)%d]+=dp[i][j][k])%=mod;
    }
    cout<<(dp[n][0][0]+dp[n][1][0]-1+mod)%mod<<endl;
}