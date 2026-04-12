#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll mod=1e9+7;
ll N,K;
vector<ll> v;
ll memo[3009][3009][2];
bool vis[3009][3009][2];
ll sol(ll a,ll b,ll t){
  if(t==0 && a==b)return v[a];
  if(a==b)return -v[a];
  if(vis[a][b][t])return memo[a][b][t];
  vis[a][b][t]=1;
  if(t==0){
    return memo[a][b][t]=max(sol(a+1,b,!t)+v[a],sol(a,b-1,!t)+v[b]);
  }
  return memo[a][b][t]=min(sol(a+1,b,!t)-v[a],sol(a,b-1,!t)-v[b]);
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		cin>>N;
		for(ll i=0;i<N;i++){
      ll a;
      cin>>a;
      v.push_back(a);
		}
		cout<<sol(0,N-1,0);
    return 0;
}