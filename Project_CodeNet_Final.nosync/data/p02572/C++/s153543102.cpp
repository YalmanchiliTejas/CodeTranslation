#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define db double
#define rep(i,a,b)    for(ll i=a;i<b;i++)
#define repn(i,a,b)   for(ll i=a;i>=b;i--)
#define F first
#define S second
#define qi queue<ll>
#define pii pair<ll,ll>
#define vi vector<ll>
#define si set<ll>
#define vii vector<pii>
#define mi multiset<ll>
#define mii multiset<pii>
#define MI map<ll,ll>
#define pb push_back
#define mp  make_pair
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define mod 998244353
#define mod2 998244353
 
const ll N=1e9+7;
 
int fexp(int a, int b){int ans = 1;while(b){if(b&1) ans = ans*a%mod2; b/=2;a=a*a%mod2;}return ans;}
int inverse(int a, int p){return fexp(a, p-2);}
 
ll solve(){
    
    return 0;
}
 
signed main(){
    IOS
// 	#ifndef ONLINE_JUDGE
//     	freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif
	ll n;
  cin>>n;
  vi v(n,0);
  ull j=0;
  rep(i,0,n){
    cin>>v[i];
    j+=v[i];
  }
  ull ans=0;
  rep(i,0,n-1){
    j-=v[i];
    ans+=(((v[i]%N)*(j%N))%N)%N;
  }
  cout<<ans%N;
    return 0;
}
// size_t f= str.find(string s,0); find s in str from start
// if found then (f != string::npos)
// m.insert({x,y}); m[x]=y;