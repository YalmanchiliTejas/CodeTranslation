#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> p;
    rep(i, m) {
	int a, b;
	cin >> a >> b;
	p.push_back(make_pair(a, b));
    }

    int g_bit = 0;
    rep (i, n)
	g_bit |= (1 << i);

    int res = 0;
    queue<pair<int, int>> que; /* now_point, flg */
    que.push(make_pair(1, 1)); /* スタート地点(現在地１、到達頂点１) */    

    while (!que.empty()) {
	pair<int, int> now = que.front();
	que.pop();

	if ((now.second & g_bit) == g_bit) {
	    res++;
	    continue;
	}
	
	rep (i, (int)p.size()) {
	    if (now.first == p[i].first) {
		if ((now.second >> p[i].second - 1) & 1) /* 到達済み */
		    continue;
		else
		    que.push(make_pair(p[i].second, now.second | (1 << (p[i].second - 1))));

	    } else if (now.first == p[i].second) {
		if ((now.second >> p[i].first - 1) & 1) /* 到達済み */
		    continue;
		else
		    que.push(make_pair(p[i].first, now.second | (1 << (p[i].first - 1))));
	    }
	}
    }

    cout << res << endl;

    return 0;
}
