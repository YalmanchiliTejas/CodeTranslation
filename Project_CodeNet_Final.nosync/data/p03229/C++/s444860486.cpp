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
int N;
vll A, B, C, tmp;

int main()
{
    cin >> N;
    A.resize(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    sort(all(A), greater<int>());
    ll ans1 = 0, ans2 = 0;
    if (N % 2 == 1)
    {
        rep(i, (N - 1) / 2)
        {
            ans1 += 2 * A[i];
            ans2 -= 2 * A[N - 1 - i];
        }
        rep(i, (N - 3) / 2)
        {
            ans1 -= 2 * A[N - 1 - i];
            ans2 += 2 * A[i];
        }
        ans1 -= A[N / 2] + A[N / 2 + 1];
        ans2 += A[N / 2] + A[N / 2 - 1];
    }
    else
    {
        rep(i, (N - 1) / 2)
        {
            ans1 += 2 * A[i];
            ans2 -= 2 * A[N - 1 - i];
        }
        rep(i, (N - 1) / 2)
        {
            ans1 -= 2 * A[N - 1 - i];
            ans2 += 2 * A[i];
        }
        ans1 += abs(A[N / 2] - A[N / 2 - 1]);
        ans2 += abs(A[N / 2] - A[N / 2 - 1]);
    }

    cout << max(ans1, ans2);
    return 0;
}