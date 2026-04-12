#include <bits/stdc++.h>
using namespace std;

void solve(long long n, vector<long long> a){
	vector<long long> b, c;
	for(int i = 0; i < n; ++i) {
		if(i % 2 == 0) {
			c.push_back(a[i]);
		} else {
			b.push_back(a[i]);
		}
	}
	if(n % 2 == 1) {
		swap(b, c);
	}
	reverse(b.begin(), b.end());
	vector<long long> d;
	d.insert(d.end(), b.begin(), b.end());
	d.insert(d.end(), c.begin(), c.end());
	for(int i = 0; i < d.size(); ++i) {
		cout << d[i] << (i == d.size() - 1 ? "\n": " ");
	}
}

int main(){	
	long long n;
	scanf("%lld",&n);
	vector<long long> a(n-1+1);
	for(int i = 0 ; i <= n-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(n, a);
	return 0;
}

