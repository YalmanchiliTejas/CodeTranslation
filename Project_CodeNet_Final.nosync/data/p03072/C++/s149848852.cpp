#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <numeric>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (int i = a; i < n; i++)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define vi vector<int>
#define ALL(a) (a).begin(), (a).end()
#define sort_v(a) sort(a.begin(), a.end())
#define fi first
#define se second

void print(bool a)
{
    if (a == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n;
    cin >> n;
    vi h(n);
    rep(i, 0, n) cin >> h[i];

    int cnt = 0, m = 0;
    rep(i, 0, n)
    {
        if (h[i] >= m)
        {
            cnt++;
        }
        m = max(m, h[i]);
    }
    cout << cnt << endl;
}
