#include <bits/stdc++.h>
using namespace std;
 
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}
 
void solve(){
 
 
}

vi a;
int dp[3009][3009][3];

ll d(int i, int s, int t){
    if(i<0 || s<0) return 0;
    return dp[i][s][t];
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();

    int n,s;cin>>n>>s;
    a.resize(n,0);
    rep(i,n)cin>>a[i];

    rep(i,n){
        rep(j,s+1) dp[i][j][1] += d(i-1, j, 1), dp[i][j][1] %= 998244353;
        rep(j,s+1) dp[i][j][1] += d(i-1, j-a[i], 1), dp[i][j][1] %= 998244353;

        dp[i][a[i]][1] += 1, dp[i][a[i]][1] %= 998244353;
        dp[i][0][1] += 1, dp[i][0][1] %= 998244353;

        rep(j,s+1) dp[i][j][2] = d(i,j,1);
        rep(j,s+1) dp[i][j][2] += d(i-1,j,2), dp[i][j][2] %= 998244353;
    }

    cout << d(n-1,s,2);

	return 0;
}
 

