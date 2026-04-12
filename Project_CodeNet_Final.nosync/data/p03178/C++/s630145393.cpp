#include <bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
#define MP make_pair
#define ld long double
 
using namespace std;
 
const int N = 5e5 + 123;
const ll mod = 1e9 + 7;

string s;
ll d, sum;
ll dp[110][10010], res;
ll steps[10010];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s >> d;
	
	steps[0] = 1;
	for(int i = 1;i <= 10000;i++)
		steps[i] = steps[i - 1] * 10 % d;


	
	dp[0][0] = 1;
	for(int i = 0;i <= 10000;i++){
		for(int j = 0;j < d;j++){
			for(int k = 0;k < 10;k++){
				dp[(j + k) % d][i + 1] = (dp[(j + k) % d][i + 1] + dp[j][i]) % mod;
			}
		}
	}
	//cout << dp[0][1] << "\n";
	for(int i = 0;i < (int)s.size();i++){
		for(int j = 0;j < s[i] - '0' + (i == ((int)s.size() - 1));j++){
			ll need = (j + sum) % d;// * steps[(int)s.size() - i - 1] % d;
	//		cerr << need << "\n";
			need = (d - need) % d; 
	//		cerr << need << " " << i << "\n";
			res = (res + dp[need][(int)s.size() - i - 1]) % mod;
			if(j == 0 && i == 0)
				res = (res - 1 + mod) % mod;
		}
	//	cerr << res << "=\n";
		sum += s[i] - '0';
	}
	cout << res;
}