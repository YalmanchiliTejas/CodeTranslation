#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

void print(vector<int> &v, int N) {
	cout << N << endl;
	for(int i = 0; i < N; ++i) {
		cout << v[i] << (i == N - 1 ? "\n": " ");
	}
}
void func(vector<int> &v) {
	int N = v.size();
	int idx = 0;
	for(int i = 1; i < N; ++i) {
		if(v[idx] < v[i]) {
			idx = i;
		}
	}
	for(int i = 0; i < N; ++i) {
		if(i == idx) {
			v[i] -= N;
		} else {
			v[i]++;
		}
	}
}

bool finished(const vector<int> &v) {
	int N = v.size();
	for(int i = 0; i < N; ++i) {
		if(v[i] >= N) {
			return false;
		}
	}
	return true;
}

bool check(vector<int> v, int m) {
	int N = v.size();
	for(int i = 0; i < m; ++i) {
		if(finished(v)) return false;
		func(v);
	}
	return finished(v);
}

signed main(){
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	int K = 0;
	while(true) {
		priority_queue<int> Q;
		vector<int> v;
		for(int i = 0; i < N; ++i) {
			Q.push(a[i]);
		}
		int L = Q.top(); Q.pop();
		if (L < 150) {
			while(!finished(a)) {
				func(a);
				++K;
			}
			cout << K << endl;
			return 0;
		}
		v.push_back(L);
		while(!Q.empty() && Q.top() >= L - N) {
			v.push_back(Q.top()); Q.pop();
		}
		int t;
		if(Q.empty()) {
			t = 50;
		} else {
			t = Q.top();
		}
		int m = v.size(), s = N - m + 1, k = (L - t - N + N) / (N + 1);
		K += m * k;
		for(int i = 0; i < m; ++i) {
			v[i] -= s * k;
		}
		while(!Q.empty()) {
			v.push_back(Q.top() + m * k);
			Q.pop();
		}
		a = v;
	}
}
