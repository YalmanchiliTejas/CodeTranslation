#include <bits/stdc++.h>
#define ll long long

using namespace std;

string s, t;

ll Dp[101][4][2][2];

ll Solve(int idx, int k, int less, int more)
{
    if (k < 0) return 0;
    if (idx == s.size())
        return k == 0; 

    ll &ret = Dp[idx][k][less][more];
    if (ret + 1) return ret;

    int numL = t[idx] - '0';
    int numR = s[idx] - '0';
    int L = (more ? 0 : numL);
    int R = (less ? 9 : numR);

    ret = 0;
    for (int i = L; i <= R; i++)
        ret += Solve(idx + 1, k - (i != 0), less | (i < numR), more | (i > numL));
    return ret;
}

int main()
{
    cin >> s;
    int k;  cin >> k;

    for (int i = 1; i < s.size(); i++)
        t.push_back('0');
    t += "1";

    memset(Dp, -1, sizeof Dp);

    cout << Solve(0, k, 0, 0) << '\n';

    return 0;
}