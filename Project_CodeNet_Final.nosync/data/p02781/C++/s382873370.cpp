#include<bits/stdc++.h>
using namespace std;

// #define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define LL long long

string s;
int K;
int len;

LL dp[101][2][4];

LL solve(int i, int res, int k) {
	if(i == len - 1) {
		if(k >= 2) {
			return 0;
		}
		else if(k == 1) {
			int maxD = res == 1? s[i]-'0' : 9;
			if(res == 1) {
				if(maxD == 0) {
					return 0;
				} else {
					return maxD;
				}
			} else {
				return 9;
			}
		}
		else {
			return 1;
		}
	}
	if(k == 0) {
		return 1;
	}

	LL &ret = dp[i][res][k];
	if(ret != -1) {
		return ret;
	}
	
	ret = 0;
	int maxD = res == 1? s[i]-'0' : 9;
	for(int d=0;d<=maxD;d++) {
		if(res == 0) {
			if(d == 0) {
				ret = ret + solve(i+1, 0, k);
			} else {
				ret = ret + solve(i+1, 0, k-1);
			}
		} else {
			if(maxD == 0) {
				ret = ret + solve(i+1, 1, k);
			} else {
				if(d == 0) {
					ret = ret + solve(i+1, 0, k);
				}
				else if(d == maxD) {
					ret = ret + solve(i+1, 1, k-1);
				}
				else {
					ret = ret + solve(i+1, 0, k-1);
				}
			}
		}
		// trace(i, res, k, maxD, d, ret);
	}
	return ret;
}

int main() {
	cin >> s >> K;
	len = (int)s.size();

	memset(dp, -1, sizeof(dp));
	LL ans = solve(0, 1, K);
	cout << ans << endl;
	return 0;
}
