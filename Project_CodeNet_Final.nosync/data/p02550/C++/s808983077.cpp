/***
 @ Author       : RobsonChen
 @ Date         : 2020-09-20 19:35:23
 @ LastEditTime : 2020-09-20 19:50:59
 @ Got AC       : Σ(っ °Д °;)っ
*/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned int INT;
typedef unsigned long long LONG;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
const int mod = 998244353;
#define debug(x) cerr << #x << ": " << (x) << '\n'
#define FW freopen("data2.txt", "w", stdout);

//快速读入输出，只适用于整数，使用时流同步打开，C语言不准关流
// getchar()<<cin(关流)<<scanf()<<cin
template <class T>
inline bool Read(T& ret)
{
    char c;
    int sgn;
    if (static_cast<void>(c = getchar()), c == EOF)
        return 0;
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (static_cast<void>(c = getchar()), c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}

//输出只能用于整数
template <class T>
inline void Write(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        Write(x / 10);
    putchar(x % 10 + '0');
}

LL sum[N * 2] = { 0 }, num = 1;

void slove(int qnum)
{
    LL n, x, m;
    cin >> n >> x >> m;
    LL ans = x;
    LL pos = 0;
    unordered_set<LL> k;
    unordered_map<LL, int> order;
    k.insert(x);
    order[x] = 1;
    sum[num] = x;
    for (int i = 2; i <= n; ++i) {
        LL cur = (x * x) % m;
        if (cur == 0) {
            cout << ans << endl;
            return;
        }
        if (k.count(cur)) {
            pos = order[cur];
            break;
        }
        num++;
        sum[num] = sum[num - 1] + cur;
        k.insert(cur);
        ans += cur;
        x = cur;
        order[cur] = i;
    }
    if (pos == 0) {
        cout << ans << endl;
        return;
    }
    ans += (ans - sum[pos - 1]) * ((n - num - 1) / (num - pos + 1));
    n = (n - num - 1) % (num - pos + 1);
    ans += (sum[pos + n] - sum[pos - 1]);
    cout << ans << endl;
}

int main()
{
    int qnum = 1;
    // cin >> num;
    for (int i = 1; i <= qnum; ++i) {
        slove(i);
    }
    // system("pause");
    return 0;
}