#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <climits>
#include <map>
#include <functional>
#include <cmath>
#include <cassert>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<pair<char,int>>> ss(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            ss[i].push_back(make_pair(s[j],count(s.begin(),s.begin()+j,s[j])));
        }
        sort(ss[i].begin(), ss[i].end());
    }
    vector<pair<char,int>> acc = ss[0];
    for (int i = 1; i < n; i++) {
        vector<pair<char,int>> tmp;
        set_intersection(acc.begin(), acc.end(),
                         ss[i].begin(), ss[i].end(),
                         back_inserter(tmp));
        acc = tmp;
    }

    for (auto it = acc.begin(); it != acc.end(); it++) {
        cout << it->first;
    }
    cout << endl;
    return 0;
}