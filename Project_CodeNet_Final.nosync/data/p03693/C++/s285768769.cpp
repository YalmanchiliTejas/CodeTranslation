#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repb(i, n) for (int i = (int)n; i >= 0; i--)
#define reps(i, m, n) for (int i = (int)m; i < (int)n; i++)
#define repsb(i, m, n) for (int i = (int)m; i >= (int)n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define INF 999999999999999999
int dy[] = {0, 0, 1, -1, 0};
int dx[] = {1, -1, 0, 0, 0};
using namespace std;
int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((100 * a + 10*b + c )% 4 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
