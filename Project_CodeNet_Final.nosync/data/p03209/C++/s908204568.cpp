#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = (1 << 28);
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
ll n, x;
ll asize[51], psize[51];
ll buger(int n, ll x)
{

    if (n == 0)
    {
        return 1;
    }
    if (x == 1)
    {
        return 0;
    }
    if (x <= asize[n - 1] + 1)
    {
        return buger(n - 1, x - 1);
    }
    if (x == asize[n - 1] + 2)
    {
        return ll(psize[n - 1] + 1);
    }
    else
    {
        return ll(buger(n - 1, x - asize[n - 1] - 2) + psize[n - 1] + 1);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> x;
    asize[0] = 1;
    psize[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        asize[i] = 2 * asize[i - 1] + 3;
        psize[i] = 2 * psize[i - 1] + 1;
    }
    cout << buger(n, x) << "\n";
}