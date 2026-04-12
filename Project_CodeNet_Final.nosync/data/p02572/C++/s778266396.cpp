#include <bits/stdc++.h>
inline int read()
{
    char c = getchar();
    int x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            s = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * s;
}
using namespace std;
#define NewNode (TreeNode *)malloc(sizeof(TreeNode))
#define Mem(a, b) memset(a, b, sizeof(a))
#define lowbit(x) (x) & (-x)
const int N = 1e3 + 5;
const long long INFINF = 0x7f7f7f7f7f7f7f;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
const int mod = 1e9 + 7;
const double II = acos(-1);
const double PP = (II * 1.0) / (180.00);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> piil;
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
    ull n, sum = 0;
    cin >> n;
    ull arr[n + 5] = {0}, ans[n + 5] = {00};
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        ans[i] = (arr[i] + ans[i - 1]);
    for (int i = 1; i <= n; i++)
        sum = ((sum + arr[i] * ((ans[n] - ans[i]) % mod)) % mod) % mod;
    cout << sum << endl;
}
