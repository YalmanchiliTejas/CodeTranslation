#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define INF (1ll<<60)

int N;

signed main() {
	deque<int> b;
	cin >> N;
	rep(i,N) {
		int a;
		cin >> a;
		if(i%2) {
			b.push_front(a);
		}else {
			b.push_back(a);
		}
	}
	if(N%2) {
		RREP(i,N) {
			cout << b[i] << (i ? " " : "");
		}
	}else {
		rep(i,N) {
			cout << (i ? " " : "") << b[i];
		}
	}
	cout << endl;
	return 0;
}