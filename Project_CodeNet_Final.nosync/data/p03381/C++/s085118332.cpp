#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
#define Flush fflush(stdout)
using namespace std;
const int N = 500050;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
    system("pause");
#endif
}
int n, m;
int a[N];
int t[N];
map<int, int> h;
int id[N];
vector<int> vec;
inline int lowbit(int x) { return x & (-x); }
inline void change(int x, int val)
{
    // puts("Flag");
    while (x <= m)
    {
        t[x] += val;
        x += lowbit(x);
    }
}
inline int query(int x)
{
    int ret = 0;
    while (x)
    {
        ret += t[x];
        x -= lowbit(x);
    }
    return ret;
}
bool check(int x)
{
    int sum = query(x);
    if (sum > (n - 1) / 2)
        return 1;
    return 0;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), vec.push_back(a[i]);
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i)
    {
        if (!h.count(vec[i]))
            h[vec[i]] = ++m, id[m] = vec[i];
    }
    // printf("%d\n", m);
    for (int i = 1; i <= n; ++i)
        change(h[a[i]], 1);
    // puts("flag");
    for (int i = 1; i <= n; ++i)
    {
        // printf("flag\n");
        change(h[a[i]], -1);
        int L = 1, R = m, ret = -1;
        while (L <= R)
        {
            int mid = (L + R) >> 1;
            if (check(mid))
                R = mid - 1, ret = mid;
            else
                L = mid + 1;
        }
        printf("%d\n", id[ret]);
        change(h[a[i]], 1);
    }
}

int main()
{
    TIME_START = clock();
    int Test = 1;
    // cin >> Test;
    while (Test--)
        solve();
    TIME_END = clock();
    program_end();
    return 0;
}