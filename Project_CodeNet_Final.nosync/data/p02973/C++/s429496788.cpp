#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), v;
	rep(i,n) cin >> a[i];
	v.push_back(a[n-1]);
	for(int i = n-2; i >= 0; i--){
		auto it = upper_bound(v.begin(), v.end(), a[i]);
		while(*it == a[i] && it != v.end()){
			it++;
		}
		if(it == v.end()) v.push_back(a[i]);
		else *it = a[i];
	}
	cout << v.size() << endl;
	return 0;
}