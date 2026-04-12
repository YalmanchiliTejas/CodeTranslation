
#include <bits/stdc++.h>
#define rep(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define print(x) cout << (x) << endl;

typedef long long ll;
const ll INF = 99999999999999;
const ll MOD = 1000000007;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll number1, ll number2)
{
    return number1 * number2 / gcd(number1, number2);
}
template <class T>
bool contain(const std::string &s, const T &v)
{
    // contain(to_string(N), '3')
    return s.find(v) != std::string::npos;
}

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    return 0;
}
using namespace std;

void transpose(vector<vector<char>> &b)
{
    if (b.size() == 0)
        return;

    vector<vector<char>> trans_vec(b[0].size(), vector<char>());

    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            trans_vec[j].push_back(b[i][j]);
        }
    }

    b = trans_vec; // <--- reassign here
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;

    vector<vector<char>> f(h, vector<char>(w));
    vector<vector<char>> ans, ans2;

    rep(i, h)
    {
        rep(j, w)
        {
            cin >> f.at(i).at(j);
        }
    }
    rep(i, h)
    {
        vector<char> a(f[i]);
        sort(all(a));
        if (a.at(0) == '#')
            ans.push_back(f[i]);
    }

    transpose(ans);
    rep(i, w)
    {
        vector<char> a(ans[i]);
        sort(all(a));
        if (a.at(0) == '#')
            ans2.push_back(ans[i]);
    }
    transpose(ans2);

    rep(i, ans2.size())
    {
        rep(j, ans2.at(0).size())
        {
            cout << ans2.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}