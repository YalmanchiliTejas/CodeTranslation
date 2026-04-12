#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

template <typename T>
inline void read(T &x)
{
    T data = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        data = (data << 3) + (data << 1) + ch - '0';
        ch = getchar();
    }
    x = f * data;
}
const int maxn = 3e5 + 9;
const ll mod = 1e9 + 7;
ll a[maxn], s[maxn];
signed main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("data.txt", "w", stdout);
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    //std::cout.tie(0);
    int n;
    read(n);
    s[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        read(a[i]);
        s[i] = (s[i - 1] + a[i]);
    }
    ll ans = 0;
    for (int i = 1; i < n; ++i)
    {
        ans += a[i] * ((s[n] - s[i]) % mod) % mod;
        ans %= mod;
    }
    cout << ans % mod << endl;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}