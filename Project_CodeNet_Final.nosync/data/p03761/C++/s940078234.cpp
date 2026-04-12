#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s.at(i);

    vector<map<char, int>> each_c(n);
    map<char, int> all_c;

    rep(i, n)
    {
        rep(j, int(s.at(i).size()))
        {
            each_c.at(i)[s.at(i).at(j)]++;
            all_c[s.at(i).at(j)]++;
        }
    }

    string answer = "";
    // for (const auto &[k, v] : all_c)
    for (map<char, int>::iterator itr = all_c.begin(); itr != all_c.end(); ++itr)
    {
        int min_cnt = INT_MAX;
        rep(i, n)
        {
            min_cnt = min(min_cnt, int(each_c.at(i)[itr->first]));
        }
        rep(i, min_cnt)
        {
            answer = answer + itr->first;
        }
        // cout << k << " " << min_cnt << endl;
    }
    cout << answer << endl;
}