#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define repi(i,a,b) for(int i=a; i<=(b); ++i)
#define rrep(i,n) for(int i=(n-1); i>=0; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define pb push_back
#define mp make_pair
#define to_s to_string
#define sz(v) (int)v.size()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
#define pr(x) cout<<(x)<<'\n'
#define debug(x) cout << #x << ": " << (x) << '\n'
#define yes "Yes"
#define no "No"
using namespace std;
using ll = long long;
using Edge = pair<int,long long>;
using Graph = vector<vector<Edge>>;
typedef pair<int,int> P;
struct aaa{aaa(){ cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);};}aaaaaaa;
int MOD = 1e9 + 7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


ll solve(ll N, ll X, ll sum){
    ll Lp = pow(2,N+1)-3;
    ll Np = pow(2,N)-1;

    if(N == 0) return sum+1;

    if(X == 1) return sum;
    if(X > 1 && X <= Lp + 1) return solve(N-1,X-1,sum);
    if(X == Lp + 2) return solve(N-1,X-2,sum+1);
    if(X > Lp + 2 && X <= 2*Lp+2) return solve(N-1,X-Lp-2,sum+Np+1);
    if(X == 2*Lp+3) return sum+2*Np+1;
}

int main(){
    ll N; cin >> N;
    ll X; cin >> X;
    pr(solve(N,X,0));
    return 0;
}
