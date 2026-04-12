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
	if(h.size() == 1){
		pair<long long, long long> res;
		res.first = modPow(2, h[0]);
		res.second = 0;
		return res;
	}
	int minH = h[0];
	for(const auto& t : h) minH = min(minH, t);
	long long alt = 2;
	long long any = 0;
	for(int i=0;i<h.size();i++){
		if(h[i] == minH){
			if(i > 0) any = (2 * any + alt) % MOD;
		} else {
			int end = i;
			while(end < h.size() && h[end] != minH) ++end;
			vector<int> nh(end - i);
			for(int j=i;j<end;j++) nh[j-i] = h[j] - minH;
			if(end - i == 1){
				auto next = solve(nh);
				if(i > 0) any = ((2 * any + alt) * next.first) % MOD;
				alt = (alt * next.first) % MOD;
			} else {
				auto next = solve(nh);
				long long addAny = 0;
				addAny += (2 * next.first) % MOD;
				addAny += next.second % MOD;
				any = (any * addAny) % MOD;
				if(i > 0){
					any = (any + alt * next.first) % MOD;
					any = (any + alt * next.second) % MOD;
				} else {
					any = (any + next.second) % MOD;
				}
				alt = (alt * next.first) % MOD;
			}
			i = end - 1;
		}
	}
	alt = (alt * modPow(2, minH-1)) % MOD;
	return make_pair(alt, any);
}

int main(){
	int N;
	while(cin >> N){
		vector<int> h(N);
		for(auto& t : h) cin >> t;
		auto res = solve(h);
		cout << (res.first + res.second) % MOD << endl;
	}
}