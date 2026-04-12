#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------
#define MOD 998244353

int inv(LLI n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r *= n,r %= MOD;
        e >>= 1;
        n *= n,n %= MOD;
    }
    return r;
}
int fact[10000001],invfact[10000001];
int main() {
    int N;
    cin >> N;

    int i;
    fact[0] = 1;
    for (i = 1; i <= N; i++) fact[i] = ((LLI) fact[i-1]*i) % MOD;
    invfact[N] = inv(fact[N]);
    for (i = N-1; i >= 0; i--) invfact[i] = ((LLI) invfact[i+1]*(i+1)) % MOD;
    LLI ans = 0,p = 1;
    for (i = 0; i < N/2; i++) p *= 2,p %= MOD;
    for (i = N/2; i >= 0; i--) {
        LLI x = fact[N];
        x *= invfact[i],x %= MOD;
        x *= invfact[N-i],x %= MOD;
        ans += x*p,ans %= MOD;
        p *= 2,p %= MOD;
        LLI y = fact[N-i];
        y *= invfact[N/2],y %= MOD;
        y *= invfact[N/2-i],y %= MOD;
        p += MOD-y,p %= MOD;
    }
    cout << ans << endl;

    return 0;
}

