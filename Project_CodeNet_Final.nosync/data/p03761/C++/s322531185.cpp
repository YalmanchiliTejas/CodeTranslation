#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1
using namespace std;
const int INF = 1e18;
const int MOD = 1000000007;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> vec(n);
    vector<map<char, int>> vecmap(n);
    rep(i, n) cin >> vec[i];

    for (int i = 0; i < n; i++)
    {
        for (int js = 0; js < vec[i].size(); js++)
        {
            vecmap[i][vec[i][js]]++;
        }
    }
    string abc = "abcdefghijklmnopqrstuvwxyz";
    vector<pair<char, int>> ans;
    for (int i = 0; i < abc.size(); i++)
    {
        int keynum = INF;
        for (int j = 0; j < n; j++)
        {
            keynum = min(vecmap[j][abc[i]], keynum);
        }
        ans.push_back(make_pair(abc[i], keynum));
    }

    string output = "";
    for (int i = 0; i < ans.size(); i++)
    {
        while (ans[i].second > 0)
        {
            output += ans[i].first;
            ans[i].second--;
        }
    }
    cout << output << endl;
}

signed main()
{
    solve();
    return 0;
}