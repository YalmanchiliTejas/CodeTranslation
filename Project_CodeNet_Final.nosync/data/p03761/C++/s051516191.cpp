#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> vv(n, vector<int>(26, 0));
	rep(i, n){
		string s;
		cin >> s;
		vector<bool> c(26, false);
		rep(j, s.size()){
			int add = s[j] - 'a';
			vv.at(i).at(add)++;
		}
	}
	rep(i, 26){
		int add = 100;
		rep(j, n){
			add = min(add, vv.at(j).at(i));
		}
		rep(j, add){
			char out = 'a' + i;
			cout << out;
		}
	}
	cout << endl;
	return 0;
}