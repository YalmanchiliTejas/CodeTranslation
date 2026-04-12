#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x: a){
		cin >> x;
	}
	vector<int> active;
	for(int i = 0; i < n; i ++){
		auto p = upper_bound(active.begin(), active.end(), a[i], greater<int>());
		if(p == active.end()){
			active.push_back(a[i]);
		}
		else{
			*p = a[i];
		}
	}
	cout << active.size();
	return 0;
}