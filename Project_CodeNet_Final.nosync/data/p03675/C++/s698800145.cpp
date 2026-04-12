#include <bits/stdc++.h>
using namespace std;

#define pb         push_back

typedef long long ll;
const ll INF = 1000000000000000000ll;
const ll MOD = 1000000007ll;
const double EPS = 1e-8;

int main(void) {
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> a;
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		a.pb(t);
	}

	int f = n % 2;

	list<int> ans;
	for(int i=0; i<n; i++){
		if(i % 2 == f){
			ans.push_back(a[i]);
		}else{
			ans.push_front(a[i]);
		}
	}

	int cnt = 0;
	for(auto x : ans){
		if(cnt != n-1)printf("%d ", x);
		else printf("%d\n", x);
		cnt++;
	}

	
	return 0;
}
