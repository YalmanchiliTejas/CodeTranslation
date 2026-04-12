#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n, ans;
vector<Int> a;
map<Int, Int> m;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	a.resize(n);
	for(auto &i:a) cin >> i;
	for(Int i=0; i<n; ++i){
		if(m.empty() || a[i] < m.begin()->first){
			m.insert(make_pair(a[i], 1));
			++ans;
			continue;
		}
		if(a[i] == m.begin()->first){
			++m[a[i]];
			++ans;
			continue;
		}
		auto j = m.lower_bound(a[i]);
		--j;
		if(j->second == 1){
			m.erase(j->first);
		}else{
			--m[j->first];
		}
		if(m.find(a[i]) == m.end()){
			m.insert(make_pair(a[i], 1));
		}else{
			++m[a[i]];
		}
	}
	cout << ans << "\n";
}