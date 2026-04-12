/*
ID: amagica1
TASK: ariprog
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define NINF -INF
#define mp make_pair
#define endl '\n'
#define boost() cin.tie(0); cin.sync_with_stdio(0)
#define For(i, a, b) for(int i=a; i<b; i++)
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define Rev(i, a, b) for(int i=a; i>b; i--)
#define REV(i, a, b) for(int i=a; i>=b; i--)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
typedef long long ll;
typedef long double ld;
typedef int64_t l;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
const ll MOD = 1e9 + 7;
const int MAXN = 100005;
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
mt19937 rng;
int N, M;
int main() {
    //-----------FILE------------//
    //freopen("airprog.in", "r", stdin);
    //freopen("airprog.out", "w", stdout);
    //----------------------------//
    cin >> N >> M;
    cout << (N == M? "Yes" : "No") << endl;
    return 0;
}
