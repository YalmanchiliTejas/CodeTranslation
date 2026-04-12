#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

typedef long long ll;

ll N;
int s, t;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

ll ask(int a, int b) {
	cout << "? " << a << " " << b << endl;
	cout.flush();
	ll ret;
	cin >> ret;
	return ret;
}

int main() {
	cin >> N >> s >> t;
	
	ll shortestpass = ask(s, t);
	
	for (int i = 1; i <= N; i++) {
		if (i == s || i == t) continue;
		ll tmp1 = ask(s, i), tmp2 = ask(i, t);
		if (tmp1 + tmp2 == shortestpass) {
			pq.push(make_pair(tmp1, i));
		}
	}

	vector<int> ans;
	ans.push_back(s);
	ll nowdis = 0;
	while (pq.size()) {
		auto now = pq.top(); pq.pop();
		ll tmp = ask(ans.back(), now.second);
		if (nowdis + tmp == now.first) {
			ans.push_back(now.second);
			nowdis += tmp;
		}
	}
	cout << "! ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		cout << " ";
	}
	cout << t << endl;
	return 0;
}
