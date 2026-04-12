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

struct edge
{
    int to, cost;
};
vector<int> G[8];
int check[8] = {0};
int N;
int func(int index)
{
    //今、indexにいる
    int result = 0;
    rep(i, G[index].size())
    {
        auto next = G[index][i];
        if (check[next] == 0)
        {
            check[next] = 1;
            result += func(next);
            check[next] = 0;
        }
    }
    int ans = 0;
    rep(i, N)
    {
        ans += check[i];
    }
    if (ans == N)
        return result + 1;
    else
        return result;
}

int main()
{
    int m;
    cin >> N >> m;
    rep(i, m)
    {
        int s, t;
        cin >> s >> t;
        G[s - 1].push_back(t - 1);
        G[t - 1].push_back(s - 1);
    }
    check[0] = 1;
    int hoge = func(0);

    cout << hoge << endl;
}