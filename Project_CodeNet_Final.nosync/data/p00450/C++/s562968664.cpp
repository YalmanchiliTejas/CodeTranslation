#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<bool, int> P;

int n;

int main() {
	while (cin >> n, n) {
		stack<P> s;
		bool before;
		{
			bool a;
			cin >> a;
			s.push(P(a, 0));
			before = a;
		}
		for (int i = 1; i < n; i++) {
			int a;
			cin >> a;
			if (i % 2 == 0) {
				//1idx??§?\???°???????????£??????
				if (s.top().first != a)s.push(P(a, i));
			}
			else {
				//1idx??§??¶??°???????????£??????
				if (s.top().first != a) {
					s.pop();
					if (s.size() == 0) {
						s.push(P(a, 0));
					}
				}
			}
		}
		int ans = 0;
		int now = n;
		while (s.size()) {
			auto tmp = s.top(); s.pop();
			if (tmp.first == 0)ans += (now - tmp.second);
			now = tmp.second;
		}
		cout << ans << endl;
	}
	return 0;
}