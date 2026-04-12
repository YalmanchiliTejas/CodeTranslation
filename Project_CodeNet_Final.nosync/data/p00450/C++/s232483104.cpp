#include<bits/stdc++.h>
#define rep(i,n)for(ll i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

int main() {
	int n;
	while (cin >> n, n) {
		stack<P>st;
		rep(i, n) {
			int d; scanf("%d", &d);
			if (!i)st.push(P(d, 1));
			else if (d == st.top().first)st.top().second++;
			else if (!(i & 1))st.push(P(d, 1));
			else {
				P p = st.top(); st.pop();
				if (st.empty())st.push(P(d, p.second + 1));
				else st.top().second += p.second + 1;
			}
		}
		int cnt = 0;
		while (!st.empty()) {
			P p = st.top(); st.pop();
			if (!p.first)cnt += p.second;
		}
		cout << cnt << endl;
	}
	return 0;
}