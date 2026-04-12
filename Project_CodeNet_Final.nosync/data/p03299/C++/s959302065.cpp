#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

long long modPow(long long a, long long p){
	if(p == 0) return 1;
	long long res = modPow(a, p/2);
	res = (res * res) % MOD;
	if(p%2 == 1) res = (res * a) % MOD;
	return res;
}

pair<long long, long long> solve(const vector<int>& h){
	if(h.empty()) return make_pair(1, 1);
	int minH = h[0];
	for(auto& t : h) minH = min(t, minH);
	if(minH > 1){
		vector<int> nh = h;
		for(auto& t : nh) t -= minH - 1;
		auto res = solve(nh);
		long long p2 = modPow(2, minH - 1);
		res.first = (res.first + (2 * p2 + MOD - 2) % MOD * res.second) % MOD;
		res.second = (res.second * p2) % MOD;
		return res;
	} else {
		for(int i=0;i<h.size();i++){
			if(h[i] == 1){
				vector<int> h1, h2;
				for(int j=0;j<i;j++) h1.push_back(h[j]);
				for(int j=i+1;j<h.size();j++) h2.push_back(h[j]);
				auto res1 = solve(h1);
				auto res2 = solve(h2);
				pair<long long, long long> res;
				res.first = 2 * res1.first * res2.first % MOD;
				res.second = res1.second * res2.second % MOD;
				return res;
			}
		}
	}
	return make_pair(0, 0);
}

int main(){
	int N;
	while(cin >> N){
		vector<int> h(N);
		for(auto& t : h) cin >> t;
		cout << solve(h).first << endl;
	}
}