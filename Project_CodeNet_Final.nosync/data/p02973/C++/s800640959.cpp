#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define ll long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;

multiset<int> s;
 
signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;	cin >> n;
	for(int i = 1; i <= n; i++){
		int p; cin >> p;
		auto it = s.lower_bound(p);
		if(it == s.begin())
			s.insert(p);
		else{
			it--;
			s.erase(it);
			s.insert(p);
		}
	}
	cout << s.size();
	return 0;
}