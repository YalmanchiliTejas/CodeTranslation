#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long


bool finished(const vector<int> &v) {
	int N = v.size();
	for(int i = 0; i < N; ++i) {
		if(v[i] >= N) {
			return false;
		}
	}
	return true;
}

signed main(){
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	int K = 0;
	while(!finished(a)) {
		int S = 0;
		for(int i = 0; i < N; ++i) {
			S += a[i] / N;
		}
		for(int i = 0; i < N; ++i) {
			a[i] = a[i] - a[i] / N * N + (S - a[i] / N);
		}
		K += S;
	}
	cout << K << endl;
	return 0;
}
