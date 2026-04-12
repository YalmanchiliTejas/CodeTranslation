#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
    int N;
    cin >> N;
    vll A(N);
    map<tuple<ll,ll,bool>, ll> dp;
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    dp[{0, 0, false}] = dp[{1, 0, false}] = 0;
    dp[{0, 1, true}] = A[0];
    dp[{1, 1, true}] = A[1];
    dp[{1, 1, false}] = A[0];
    for (int i = 0; i+2 < N; i++)
    {
        for (int j = i / 2; j <= i / 2 + 1; j++)
        {

            dp[{i + 2, j + 1, true}] = max(dp[{i, j, true}], dp[{i, j, false}]) + A[i + 2];
            dp[{i + 2, j + 1, false}] = dp[{i, j, false}] + A[i + 1];
            dp[{i+2,j,true}]=max(dp[{i,j-1,true}],dp[{i,j-1,false}])+A[i+2];
            dp[{i+2,j,false}]=max(dp[{i+1,j,false}],dp[{i+1,j,true}]);
        }
    }
    cout<<max(dp[{N-1,N/2,false}],dp[{N-1,N/2,true}]);
    return 0;
}