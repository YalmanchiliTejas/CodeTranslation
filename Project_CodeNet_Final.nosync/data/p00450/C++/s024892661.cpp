#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
//#define int long long
using namespace std;
typedef long long ll;

int n;
int color;

signed main()
{
	while (true) {
		cin >> n;
		if (n == 0) break;

		vector<pair<int, int> > vpii;
		for (int i=1; i<=n; i++) {
			cin >> color;
			if (i == 1) {
				vpii.push_back(make_pair(color, 1));
				continue;
			}
			if (i % 2 == 0) {
				//??¶??°??????
				if (vpii[vpii.size()-1].first == color) {
					vpii[vpii.size()-1].second += 1;
				} else {
					vpii[vpii.size()-1].first = color;
					vpii[vpii.size()-1].second += 1;
					if (vpii.size() >= 2 && vpii[vpii.size()-2].first == color) {
						vpii[vpii.size()-2].second += vpii[vpii.size()-1].second;
						vpii.pop_back();
					}
				}
			} else {
				//?\???°??????
				if (vpii[vpii.size()-1].first == color) {
					vpii[vpii.size()-1].second += 1;
				} else {
					vpii.push_back(make_pair(color, 1));
				}
			}
		}

		int ans = 0;
		rep(i,vpii.size()) {
			//printf("color = %d, num = %d\n", vpii[i].first, vpii[i].second);
			if (vpii[i].first == 0) {
				ans += vpii[i].second;
			}
		}
		cout << ans << endl;
	}
}