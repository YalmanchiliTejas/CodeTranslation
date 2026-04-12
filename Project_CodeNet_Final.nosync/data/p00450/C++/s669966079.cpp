#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <iomanip>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n, cnt[100005];

// o o * * o o o o
// o o * * * * * *

// o
// * *
// * * *
// o o o o
// o o o o *
// o o o o o o
// o o o o o o o
// o o o o o o o o
// o o o o o o o o o
// o o o o o o o o o o
// * * * * * * * * * * *
// * * * * * * * * * * * *
// * * * * * * * * * * * * *
// * * * * * * * * * * * * * *
// * * * * * * * * * * * * * * *
// o o o o o o o o o o o o o o o o
// o o o o o o o o o o o o o o o o *
// o o o o o o o o o o o o o o o o o o
// o o o o o o o o o o o o o o o o o o o
// * * * * * * * * * * * * * * * * * * * *

void de(vector<int> v) {
	REP(i, 1, n + 1) {
		cout << setw(2) << v[i] << " ";
	}
	cout << endl;
}

void cde() {
	REP(i, 1, n+1) {
		cout << setw(2) << cnt[i] << " ";
	}
	cout << endl;
}

void sp(stack<int> st) {
	while(st.size()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main() {
	while(cin >> n && n) {
		memset(cnt, 0, sizeof(cnt));

		vector<int> v(n+1);
		rep(i, n) cin >> v[i+1];

		stack<int> w, b;
		REP(i, 1, n+1) {
			if(i % 2 == 0 && v[i] != v[i-1]) {
				cnt[i-1]++;
				if(v[i] == 0) {
					if(w.size()) {
						int p = w.top();
						w.pop();
						cnt[p]--;

					}

					if(b.size()) b.pop();
				} else {
					if(b.size()) {
						int p = b.top();
						b.pop();
						cnt[p]--;

					}

					if(w.size()) w.pop();
				}
			}

			// cout << "i:" << i << " ";
			// cde();

			if(v[i] == 0) {
				if(w.size() && w.top() + 1 == i) {
					w.pop();
				}
				w.push(i);
			}
			else {
				if(b.size() && b.top() + 1 == i) {
					b.pop();
				}
				b.push(i);
			}

			// sp(w);
			// sp(b);
		}
		
		// cde();
		// de(v);

		for(int i = n; i >= 1; i--) {
			cnt[i-1] += cnt[i];
		}


		REP(i, 1, n+1) {
			if(cnt[i]%2 == 0) continue;
			v[i] = !v[i];
		}

		// cde();
		// de(v);

		int ans = 0;
		REP(i, 1, n+1) {
			ans += !v[i];
		}

		cout << ans << endl;
	}
	return 0;
}