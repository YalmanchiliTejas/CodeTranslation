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
	vector<int> a;
	cin >> n;

	int f = n % 2;
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		if(f){
			if(i % 2 == f){
				a.pb(t);
			}else{
				a.insert(a.begin(), t);
			}
		}else{
			if(i % 2 == f){
				a.pb(t);
			}else{
				a.insert(a.begin(), t);
			}
		}
	}
	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	puts("");
	
	return 0;
}
