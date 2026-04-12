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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}
template <class T, class U> void amin(T& x, U y) {if (x > y) x = y;}

int main(void)
{
    ll N, K, result;
    cin >> N >> K;
    if (K == 0) {
        result = N * N;
    } else {
        result = 0;
        FOR(b, K + 1, N + 1) {
            ll q = N / b;
            ll r = N % b;
            result += (b - K) * q + max(0ll, r - K + 1);
        }
    }
    cout << result << endl;
    return 0;
}
