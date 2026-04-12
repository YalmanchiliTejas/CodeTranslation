#include <bits/stdc++.h>
using namespace std;
const int maxn = 234567;
int a[maxn], v[maxn];
int main(){
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 1;
	multiset<int> good; good.insert(a[1]);
	for(int i = 2; i <= n; i++){
		auto it = good.lower_bound(a[i]);
		if(it == good.begin()){
			ans++;
		} else {
			it--;
			good.erase(it);
		}
		good.insert(a[i]);
	}
	cout << ans << endl;
	return 0;
}
