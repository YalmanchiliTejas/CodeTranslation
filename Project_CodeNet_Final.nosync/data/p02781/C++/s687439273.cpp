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
	string s;
	cin >> s;
	int K;
	cin >> K;
	vector<vector<vector<int>>> dp(s.size()+1, vector<vector<int>>(K+1, vector<int>(2, 0)));
	dp.at(0).at(0).at(0) = 1;
	rep(i, s.size()){
		int now = s[i] - '0';
		int ni = i+1;
		rep(j, K+1)rep(k, 2)rep(l, 10){
			int nj = j, nk = k;
			if(l != 0) nj++;
			if(nj > K) continue;
			if(nk == 0){
				if(l > now) continue;
				else if(l < now) nk = 1;
			}
			dp.at(ni).at(nj).at(nk) += dp.at(i).at(j).at(k);
		}
	}
	// rep(i, s.size()+1){
	// 	rep(j, K+1){
	// 		cout << dp.at(i).at(j).at(0) << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	// rep(i, s.size()+1){
	// 	rep(j, K+1){
	// 		cout << dp.at(i).at(j).at(1) << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp.at(s.size()).at(K).at(0) +  dp.at(s.size()).at(K).at(1) << endl;
	return 0;
}