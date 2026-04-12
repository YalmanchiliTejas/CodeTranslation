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
#define MOD 1000000007

char S[200000];
int fib[200005],dp[200005];
int main() {
    int i;
    int N,M;
    scanf("%d %d",&N,&M);
    for (i = 0; i < M; i++) scanf(" %c",&S[i]);

    for (i = 0; i < M; i++) {
        if (S[i] != S[0]) break;
    }
    if (i == M) {
        fib[0] = fib[1] = 1;
        for (i = 2; i < N+5; i++) fib[i] = (fib[i-1]+fib[i-2]) % MOD;
        printf("%d\n",(fib[N-2]+fib[N]) % MOD);
    }
    else {
        if (N & 1) printf("0\n");
        else {
            N /= 2;
            int B = 1e9,c = 0,f = 1;
            for (i = 0; i < M; i++) {
                if (S[i] == S[0]) c++;
                else {
                    if (f) B = min(B,(c & 1) ? c:c+1),f = 0;
                    else if (c & 1) B = min(B,c);
                    c = 0;
                }
            }
            B = (B+1)/2;
            dp[0] = 1;
            int sum = 1;
            for (i = 1; i < N+5; i++) {
                dp[i] = sum;
                sum += dp[i],sum %= MOD;
                if (i >= B) sum -= dp[i-B],sum %= MOD;
            }
            int ans = dp[N];
            for (i = 1; i < B; i++) {
                if (N-i-1 >= 0) {
                    ans += ((LLI) i*dp[N-i-1]) % MOD;
                    ans %= MOD;
                }
            }
            ans = (2*ans) % MOD;
            if (ans < 0) ans += MOD;
            printf("%d\n",ans);
        }
    }

    return 0;
}

