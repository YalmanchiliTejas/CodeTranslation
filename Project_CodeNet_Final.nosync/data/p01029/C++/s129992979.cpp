#include <bits/stdc++.h>
using namespace std;
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG false
// sort(a.begin(), a.end(), std::greater<int>());

/*
std::vector<std::string> split(const std::string &input, char delimiter)
{
    std::istringstream stream(input);

    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter))
    {
        result.push_back(field);
    }
    return result;
}
*/
/*
int dfs(int foo, int timer)
{
    //foo is node number
    if (finds[foo].first != -1)
        return timer;
    finds[foo].first = ++timer;
    int result = timer;
    if (data[foo].size() != 0)
    {
        rep(i, data[foo].size())
        {
            result = dfs(data[foo][i], result);
        }
    }
    finds[foo].second = ++result;
    return result;
}
*/

int main()
{
    int v, e;
    string s;
    cin >> v >> e;
    rep(i, v)
    {
        char hoge;
        cin >> hoge;
        s.push_back(hoge);
    }
    map<int, set<int>> a;
    rep(i, e)
    {
        int x, y;
        cin >> x >> y;
        a[x].insert(y);
        a[y].insert(x);
    }
    rep(i, s.size())
    {
        set<char> hoge;
        rep(k, 26)
        {
            hoge.insert('a' + k);
        }
        if (s[i] != '?')
            continue;
        else
        {
            for (auto itr = a[i].begin(); itr != a[i].end(); itr++)
            {
                hoge.erase(s[*itr]);
            }
            s[i] = *hoge.begin();
        }
    }
    cout << s << endl;
    return 0;
}
