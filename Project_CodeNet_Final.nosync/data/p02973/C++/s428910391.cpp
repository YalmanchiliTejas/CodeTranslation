#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	deque<ll> d;
	rep(i,n){
		int p = lower_bound(d.begin(),d.end(),a[i]) - d.begin();
		if(p == 0){
			d.push_front(a[i]);
		}else{
			d[p-1] = a[i];	
		}
	}
	cout << d.size() << endl;
	return 0;
}