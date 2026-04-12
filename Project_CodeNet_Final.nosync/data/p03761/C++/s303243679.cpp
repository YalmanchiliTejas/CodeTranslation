#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>

typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i <= b; i++)
#define revrep(i, s) for (int i = s-1; i > 0; i--)
#define revrrep(i, s) for (int i = s-1; i >= 0; i--)
#define all(a)  begin((a)),end((a))
#define uniq(c) (c).erase(unique(all((c))), end((c)))

int main()
{
    int n; cin >> n;
    vector<map<char, int>> counts;
    vector<vector<char>> keys;
    rep (i, 0, n) {
        string S; cin >> S;
        vector<char> tmp;
        map<char, int> mp;
        for (auto c : S) {
            tmp.push_back(c);
            mp[c] += 1;
        }
        counts.push_back(mp);
        uniq(tmp);
        sort(tmp.begin(), tmp.end());
        keys.push_back(tmp);
    }

    vector<char> fin_keys = keys[0];
    rep (i, 1, keys.size()) {
        vector<char> tmp;
        set_intersection(fin_keys.begin(), fin_keys.end(),
                         keys[i].begin(), keys[i].end(),
                         back_inserter(tmp));
        fin_keys = tmp;
    }

    map<char, int> ans;
    for (auto key : fin_keys) {
        for (auto mp : counts) {
            if (mp.find(key) != mp.end()) {
                if (ans.find(key) != ans.end())
                    ans[key] = min(ans[key], mp[key]);
                else
                    ans[key] = mp[key];
            }
        }
    }

    for (auto pair : ans) {
        rep (i, 0, pair.second)
            cout << pair.first;
    }
    cout << endl;
}