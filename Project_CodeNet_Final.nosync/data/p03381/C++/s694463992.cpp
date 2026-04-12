#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; ++ i){
		cin >> a[i].first, a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<int> res(n);
	for(int i = 0; i < n / 2; ++ i){
		res[a[i].second] = a[n / 2].first;
	}
	for(int i = n / 2; i < n; ++ i){
		res[a[i].second] = a[n / 2 - 1].first;
	}
	for(int i = 0; i < n; ++ i){
		cout << res[i] << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////