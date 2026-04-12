/***********************************************
#
#      Filename: e.cpp
#
#        Author: Comsyl - ylsong15@fudan.edu.cn
#   Description: ---
#        Create: 2017-04-29 21:51:42
***********************************************/
#include <bits/stdc++.h>
#define LL long long
using namespace std;
typedef pair<int, int> pii;
vector<pii> d;
set<pii> s;

int main()
{
    int N;
    cin >> N;
    int r, b;
    for (int i = 0; i < N; ++ i) { 
        cin >> r >> b;
        if (r > b) swap(r, b);
        d.push_back(make_pair(r, b));
    }
    sort(d.begin(), d.end());
    set<pii> red, blue;
    for (int i = 0; i < d.size(); ++ i) {
        red.insert(pii(d[i].first, i));
        blue.insert(pii(d[i].second, i));
    }
    LL ans = ( red.rbegin()->first - red.begin()->first ) * 1LL * ( blue.rbegin()->first - blue.begin()->first );
    for (int i = 0; i < d.size(); ++ i) {
        red.erase(pii(d[i].first, i));
        blue.erase(pii(d[i].second, i));
        red.insert(pii(d[i].second, i));
        blue.insert(pii(d[i].first, i));
        LL tmp = ( red.rbegin()->first - red.begin()->first ) * 1LL * ( blue.rbegin()->first - blue.begin()->first );
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
