#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(x)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl;
#define PRINTA(a,first,last)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<(first)<<", "<<(last)<<")"<<endl;\
    for (int i=(first);i<(last);++i){cout<<#a<<"["<<i<<"] = "<<(a)[i]<<endl;}
#else
#define PRINT(x)
#define PRINTA(a,first,last)
#endif

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}
template <class T, class U> void amin(T& x, U y) {if (x > y) x = y;}

int main(void)
{
    constexpr int N_MAX = 3000;
    int N;
    int a[N_MAX];
    cin >> N;
    REP(i, N) cin >> a[i];

    ll sum[N_MAX + 1];
    sum[0] = 0;
    REP(i, N) sum[i + 1] = sum[i] + a[i];

    ll dp[N_MAX][N_MAX];
    REP(i, N) REP(j, N) dp[i][j] = -1;

    function<ll(int, int)> f = [&](int first, int last) -> ll {
        if (dp[first][last] != -1) {
            return dp[first][last];
        }
        if (first == last) {
            return dp[first][last] = a[first];
        }
        return dp[first][last] = sum[last + 1] - sum[first] - min(f(first + 1, last), f(first, last - 1));
    };

    ll X = f(0, N - 1);
    ll Y = sum[N] - X;
    cout << X - Y << endl;
    return 0;
}

