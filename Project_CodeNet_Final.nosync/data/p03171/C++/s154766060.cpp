#include <bits/stdc++.h>

using namespace std;
typedef long long lint;

#define RPT(i, b, e) for (int i = (b); i <= (e); i++)
#define RPT0(i, n) RPT(i, 0, n - 1)
#define RPT1(i, n) RPT(i, 1, n)
#define EACH(it, v) for (const auto& it : v)
#define ALL(v) v.begin(), v.end()

int N;
vector<int> a;

// 区間i,jが残っているときのX-Y
lint dp[3001][3001];
bool df[3001][3001];

lint f(int l, int r)
{
    if (l > r) return 0;
    if (df[l][r]) return dp[l][r];

    df[l][r] = true;
    bool turn = ((N - (r - l)) % 2 == 1);
    dp[l][r] = turn ? max(f(l + 1, r) + a[l - 1], f(l, r - 1) + a[r - 1])
                    : min(f(l + 1, r) - a[l - 1], f(l, r - 1) - a[r - 1]);
    return dp[l][r];
}

void resolve()
{
    cin >> N;
    RPT0(i, N)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    RPT1(i, N) RPT1(j, N) df[i][j] = false;
    lint ans = f(1, N);
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    resolve();
    return 0;
}
