/*+lmake
 * STD = c++14
 * DEFINE += MDEBUG
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#ifdef MDEBUG
#define debug(args...)                                                                             \
    {                                                                                              \
        dbg, args;                                                                                 \
        cerr << endl;                                                                              \
    }
#else
#define debug(args...) // Just strip off all debug tokens
#endif

struct debugger
{
    template <typename T>
    debugger &operator,(const T &v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;
#define MAXN 200000
int p[MAXN + 10];
void solve(long long N, vector<long long> X)
{
    vector<pair<LL, int>> a;
    for (int i = 0; i < N; ++i) {
        a.push_back(make_pair(X[i], i));
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < N; ++i) {
        p[a[i].second] = i;
    }
    int z = N / 2;
    for (int i = 0; i < N; ++i) {
        if (p[i]+1 <= z) {
            printf("%lld\n", a[z ].first);
        } else {
            printf("%lld\n", a[z-1].first);
        }
    }
}

int main()
{
	//freopen("in_C_1.txt","r",stdin);
    long long N;
    scanf("%lld", &N);
    vector<long long> X(N - 1 + 1);
    for (int i = 0; i <= N - 1; i++) {
        scanf("%lld", &X[i]);
    }
    solve(N, X);
    return 0;
}
