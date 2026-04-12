#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

using ld=long double;

vector<long long int> divisor(long long int n) {

	vector<long long int> res;
	for (long long int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	sort(begin(res), end(res));
	return res;
}
int main() {	
	int N;cin>>N;
	vector<int>ts;
	for (int i = 0; i < N; ++i) {
		int t;cin>>t;
		ts.push_back(t);
	}
	int tmax=*max_element(ts.begin(),ts.end());
	int ans=0;
	auto divs=divisor(tmax);
	for (int i = 0; i < N; ++i) {
		int t=ts[i];
		ans+=*lower_bound(divs.begin(),divs.end(),t)-t;
	}
	cout<<ans<<endl;
	return 0;
}