#include <bits/stdc++.h>
#define rep(i, n) for(ll i=0; i<(n); ++i)
#define rep1(i,n) for(ll i=1; i<=(n); ++i)
#define repi(i,a,b) for(ll i=a; i<=(b); ++i)
#define rrep(i,n) for(ll i=(n-1); i>=0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define pb push_back
#define mp make_pair
#define to_s to_string
#define sz(v) (int)v.size()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define print(x) cout<<(x)<<'\n'
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
using Edge = pair<ll,ll>;
using Graph = vector<vector<Edge>>;
typedef pair<ll,ll> P;
struct aaa{aaa(){ cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}aaaaaaa;
int MOD = 1e9 + 7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll devc(ll x, ll y){return 1 + (x-1)/y;}

ll solve(ll N){
    ll ans = 0;
    return ans;
}

int main(){
    ll N,M; cin >> N >> M;
    if(N==M) print("Yes");
    else print("No");
    return 0;
}