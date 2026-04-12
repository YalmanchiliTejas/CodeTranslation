#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
#define LL long long
// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

//方針
//前からずっとシミュレーションして、
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> num(n, vector<int>(26));
    rep(i, n)
    {
        string hoge;
        cin >> hoge;
        rep(j, 26)
        {
            num[i][j] = 0;
        }
        rep(j, hoge.size())
        {
            num[i][(int)(hoge[j] - 'a')]++;
        }
    }
    int ans[26] = {0};
    if (DEBUG)
        cout << "fuck" << endl;
    rep(i, 26)
    {
        int huga = INT_MAX;
        rep(j, n)
        {
            huga = min(huga, num[j][i]);
        }
        ans[i] = huga;
    }
    rep(i, 26)
    {
        int huga = ans[i];
        rep(j, huga)
        {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;
    return 0;
}