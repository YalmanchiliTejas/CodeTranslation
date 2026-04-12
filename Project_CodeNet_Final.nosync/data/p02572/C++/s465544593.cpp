#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INT int
#define MOD 1000000007

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
template <typename T>
void print(T x)
{
    std::cout << x << '\n';
}
typedef long long ll;
const long long INF = 1LL << 60;

signed main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    int ans = 0;
    int s = 0;
    rep1(i, a.size())
    {
        s = s + a[i];
        s = s % MOD;
    }

    //cout << s << endl;

    rep(i, a.size() - 1)
    {
        int temp = a[i] * s % MOD;
        ans = (ans + temp) % MOD;
        s = (s + MOD - a[i + 1]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
