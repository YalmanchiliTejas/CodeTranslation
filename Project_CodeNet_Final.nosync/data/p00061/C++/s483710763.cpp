#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<pair<int, int>> v;
    string s;
    while(cin >> s)
    {
        if(s == "0,0") break;
        int idx = -1;
        for(int i = 0; i < s.size(); i++) if(s[i] == ',') idx  = i;
        int num = stoi(s.substr(0, idx));
        int score = stoi(s.substr(idx + 1));
        v.push_back(make_pair(score, num));
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int val = 0, rank = 0;
    vector<int> result(110);
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].first != val)
        {
            rank++;
            val = v[i].first;
        }
        result[v[i].second] = rank;
    }
    int q;
    while(cin >> q)
    {
        cout << result[q] << endl;
    }
    return 0;
}


