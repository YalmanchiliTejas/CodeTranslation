#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9+100;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, x, m;
	cin>>n>>x>>m;
	map<int, int> vals;
	int cycStart;
	vector<int> sequence;
	// ll val = x;
	int id = 0;
	while (vals.count(x) == 0){
		vals[x] = id;
		sequence.push_back(x);
		x *= x; x %= m;
		id++;
	}
	cycStart = vals[x];
	int len = id;
	// for (auto it: sequence){
	// 	cout<<it<<' ';
	// }
	// cout<<'\n';
	// cout<<cycStart<<'\n';
	if (n < cycStart){
		ll res = 0;
		for (int i = 0; i < n; i++){
			res += sequence[i];
		}
		cout<<res<<'\n';
	}else{
		ll res = 0;
		ll cycsum = 0;
		for (int i = 0; i < cycStart; i++){
			res += sequence[i];
		}
		for (int i = cycStart; i < len; i++){
			cycsum += sequence[i];
		}
		n -= cycStart;
		res += n/(len - cycStart)*cycsum;
		n = n % (len - cycStart);
		for (int i = cycStart; i < cycStart + n; i++){
			res += sequence[i];
		}
		cout<<res<<'\n';
	}
	return 0;
}