#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;

ll dp[MAX];

int main(){
  ll N;cin>>N;
  vector<ll> a(N);
  ll i,j,k,l;
  rep(i,N) cin>>a[i];
  fill(dp,dp+N,INF+1);
  for(i=N-1;i>=0;i--){
    *upper_bound(dp,dp+N,a[i]) = a[i];
  }
  ll ans=(lower_bound(dp,dp+N,INF+1)-dp);
  cout<<ans<<endl;
}
