#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i=0; i<int(n); i++)
#define RNG(i, f, t) for(int i=int(f); i<=int(t); i++)
#define REV(i, f, t) for(int i=int(f); i>=int(t); --i)
bool RELAXED = false;
template<int,typename T> struct MINMAX{ T val; MINMAX(T val) : val(val) {} };
template<typename T> MINMAX<1,T> MAX(T val) { return MINMAX<1,T>(val); };
template<typename T> MINMAX<2,T> MIN(T val) { return MINMAX<2,T>(val); };
template<typename T, typename U> inline T& operator|=(T &lhs, MINMAX<1,U> rhs) { return lhs = (rhs.val > lhs ? (RELAXED=true,rhs.val) : (RELAXED=false,lhs)); }
template<typename T, typename U> inline T& operator|=(T &lhs, MINMAX<2,U> rhs) { return lhs = (rhs.val < lhs ? (RELAXED=true,rhs.val) : (RELAXED=false,lhs)); }
template<typename T> inline vector<T> readVector(int n) { vector<T> vec(n); FOR(i,n) cin>>vec[i]; return vec; }
template<typename T> void EXIT(T answer) { cout<<answer<<endl; exit(0); }
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef signed long long int ll;

const int MOD = 998244353;
int dp[3005];
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, S;
    cin>>n>>S;
    vi a = readVector<int>(n);

    FOR(i,n) {
        int ai = a[i];
        REV(s, S-ai, 0) {
            dp[s+ai] += dp[s];
            dp[s+ai] %= MOD;
        }
        dp[ai] += i+1;
        dp[ai] %= MOD;

//        cerr<<i<<" = "<<dp[S]<<endl;
        ans += dp[S];
        ans %= MOD;
    }

    cout<<ans<<endl;
}

