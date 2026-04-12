#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	int N; cin >> N;
	vector<int> A(N);
	rep(i, N) cin >> A[i];
	sort(all(A));

	ll ans = 0;
	rep(i, 2) {
		deque<int> dq;
		int l = 0, r = N-1;
		// 小さい方から開始して、小→大大→小小→..
		if (i==0 ) dq.push_back(A[l++]);
		else dq.push_back(A[r--]);

		int now = i;
		while (r-l>=1) {
			if (now%2==0) {
				dq.push_front(A[r--]);
				dq.push_back(A[r--]);
			} else {
				dq.push_front(A[l++]);
				dq.push_back(A[l++]);
			}
			now++;
		}
		if (l==r) {
			if (abs(dq.back()-A[l])>abs(dq.front()-A[l])) dq.push_back(A[l]);
			else dq.push_front(A[l]);
		}

		ll tmp = 0;
		rep(j, N-1) {
			tmp += abs(dq[j]-dq[j+1]);
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;	
}