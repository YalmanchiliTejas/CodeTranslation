#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

#define INX(x) (cin >> x)
#define OUTX(x) (cout << x << endl)

#define ADD emplace_back
#define MP make_pair
#define VVEC(type) vector<vector<type>>

#define MOD 1000000007

int main()
{
    ll N;
    INX(N);

    vll A(N);
    for (ll i = 0; i < N; i++)
    {
        INX(A[i]);
    }

    ll result = 0;
    ll tmp = A[N - 1];
    for (ll i = N - 2; i >= 0; i--)
    {
        result += A[i] * tmp;
        result %= MOD;
        tmp += A[i];
        tmp %= MOD;
    }
    OUTX(result);    


    return 0;
}
