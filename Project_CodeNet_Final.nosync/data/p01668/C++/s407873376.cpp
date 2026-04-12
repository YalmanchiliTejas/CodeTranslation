#include <iostream>
#include <string>
#define llint long long
#define mod 1000000007

using namespace std;

string a, b, c;
llint next[505][10];
llint dp[2][505][3];
llint cnt[10000][505][3];

void count(string s)
{
	for(int i = 0; i <= s.size(); i++){
		for(int j = 0; j < c.size(); j++){
			for(int k = 0; k < 3; k++){
				cnt[i][j][k] = 0;
			}
		}
	}
	cnt[0][0][0] = 1;
	
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < c.size(); j++){
			for(int k = 0; k < 3; k++){
				for(int l = 0; l < 10; l++){
					if(i == 0 && l == 0) continue;
					if(k == 0){
						int nk = 0;
						if(l > s[i] - '0') nk = 2;
						if(l < s[i] - '0') nk = 1;
						cnt[i+1][next[j][l]][nk] += cnt[i][j][0];
						cnt[i+1][next[j][l]][nk] %= mod;
					}
					else{
						cnt[i+1][next[j][l]][k] += cnt[i][j][k];
						cnt[i+1][next[j][l]][k] %= mod;
					}
				}
				
			}
		}
	}
}

llint calc(string s)
{
	if(s == "0") return c == "0";
	count(s);
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < c.size(); j++){
			for(int k = 0; k < 3; k++){
				dp[i][j][k] = 0;
			}
		}
	}
	
	llint ret = 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < c.size(); j++){
			for(int k = 0; k < 3; k++){
				dp[(i+1)%2][j][k] = 0;
			}
		}
		for(int j = 0; j < c.size(); j++){
			for(int k = 0; k < 3; k++){
				for(int l = 0; l < 10; l++){
					if(i == 0 && l == 0) continue;
					int ac = 0;
					if(j == c.size()-1 && l == c[c.size()-1] - '0') ac = 1;
					if(k == 0){
						int nk = 0;
						if(l > s[i] - '0') nk = 2;
						if(l < s[i] - '0'){
							nk = 1;
						}
						dp[(i+1)%2][next[j][l]][nk] += dp[i%2][j][0] + ac * cnt[i][j][0];
						dp[(i+1)%2][next[j][l]][nk] %= mod;
					}
					else{
						dp[(i+1)%2][next[j][l]][k] += dp[i%2][j][k] + ac * cnt[i][j][k];
						dp[(i+1)%2][next[j][l]][k] %= mod;
					}
				}
			}
		}
		if(i != 0){
			for(int j = 0; j < c.size(); j++){
				for(int k = 0; k < 3; k++){
					ret += dp[i%2][j][k];
					ret %= mod;
				}
			}
		}
	}
	for(int j = 0; j < c.size(); j++){
		for(int k = 0; k < 2; k++){
			ret += dp[s.size()%2][j][k];
			ret %= mod;
		}
	}
	if(c == "0") ret++, ret %= mod;
	return ret;
}

int main(void)
{
	cin >> a >> b >> c;
	
	for(int i = 0; i < c.size(); i++){
		for(int j = 0; j < 10; j++){
			string s = c.substr(0, i) + (char)('0' + j);
			if(s.size() >= c.size()) s = s.substr(1);
			while(s != c.substr(0, s.size())) s = s.substr(1);
			next[i][j] = s.size();
		}
	}
	
	llint ans = calc(b);
	ans += mod - calc(a);
	ans %= mod;
	for(int i = 0; i <= (int)a.size() - (int)c.size(); i++){
		if(a.substr(i, c.size()) == c) ans++, ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}
