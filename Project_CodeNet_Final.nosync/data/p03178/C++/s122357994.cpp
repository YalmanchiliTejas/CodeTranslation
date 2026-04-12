#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i=0; i<int(n); i++)
#define RNG(i, f, t) for(int i=int(f); i<=int(t); i++)
#define REV(i, f, t) for(int i=int(f); i>=int(t); --i)
#define ALL(v) (v).begin(), (v).end()
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

const int MOD=1e9+7;
int dp[10005][105][2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string K;
    int D;
    cin>>K>>D;
    int n = K.length();

    dp[0][0][1]=1;

    FOR(i,n) {
        FOR(d, 10) {
            FOR(m,D) {
                int nm=(((m-d)%D)+D)%D;
                dp[i+1][nm][0] += dp[i][m][0];
                if(d<K[i]-'0')
                    dp[i+1][nm][0] += dp[i][m][1];
                if(d==K[i]-'0')
                    dp[i+1][nm][1] += dp[i][m][1];
                dp[i+1][nm][0] %= MOD;
            }
        }
    }

    ll ans =dp[n][0][0]+dp[n][0][1]-1+MOD;
    cout<<ans%MOD<<endl;


    return 0;
}

