#include <bits/stdc++.h>
using namespace std;
ofstream fo("output.out");
#define fast() {ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define out(a) { fo << #a << ":" << (a) <<" ";}
#define outv(a) { fo << "["; \
	for(int i = 0; i < (a).size(); ++i){ \
		fo << i <<":" << a[i] <<" "; \
		if(i % 10 == 9) fo <<"\n"; \
		} \
	fo << "]"; \
}
#define outvv(a) { fo << "["; \
	for(int i = 0; i < a.size(); ++i){ \
		for(int j = 0; j < a[i].size(); ++j){ \
			fo << "(" << i <<"," <<j <<")" <<":" << a[i][j] <<" "; \
		} \
		fo << "\n"; \
	} \
	fo << "]"; \
}
#define outp(a) { fo <<"[" << #a << ".fi:"<<a.first; \
					fo << " "<< #a << ".se:" << a.second <<"]"; }
using ll = long long;
const int mod = 1e9 + 7;
const int nax = 10123;
void add_self(int &a, int b){
	a += b;
	if(a > mod){
		a -= mod;
	}
}
int main()
{
	string s;
	cin >> s;
	int D;
	cin >> D;
	vector<vector<int>>dp(D, vector<int>(2, 0));
	dp[0][0] = 1;
	for(int where = 0; where < s.length(); ++where){
		vector<vector<int>> new_dp(D, vector<int>(2, 0));
		for(int sum = 0; sum < D; ++sum){
			for(bool sm_already: {false, true}){
				for(int digit = 0; digit < 10; ++digit){
					if(digit > s[where] - '0' && !sm_already){
						break;
					}
					add_self(new_dp[(sum + digit) % D][sm_already||digit < s[where] - '0'],
						dp[sum][sm_already]);
				}
			}
		}
		dp = new_dp;
	}
	int ans = 0 ;
	ans += (dp[0][false] + dp[0][true])%mod;
	ans--;
	if(ans == - 1){
		ans = mod - 1;
	}
	cout << ans;
}