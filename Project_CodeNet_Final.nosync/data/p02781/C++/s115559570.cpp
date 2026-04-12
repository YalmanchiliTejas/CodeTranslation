#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

long long INF=LLONG_MAX;

ll dp[102][4][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	string s; 
	int K; 
	cin >> s >> K;
	memset(dp,0,sizeof(dp));
	int n = s.length();
	dp[0][0][0] = 1;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		int cur = s[i]-'0';
		for(int j = 0; j <= K; j++){
			for(int k = 0; k < 2; k++){
				if(dp[i][j][k]==0)continue;
				for(int num = 0; num < 10; num++){
					if(k==0&&num>cur)continue;
					if(j+(num>0)>K)continue;
					dp[i+1][j+(num>0)][k|(num<cur)] += dp[i][j][k];
					//cout << i << ' ' << j << ' ' << k << " | "<< num << ' ' <<  i+1 << ' ' << int(j+(num>0?1:0)) << ' ' << int(k|(num<cur?1:0)) << ' ' <<dp[i+1][int(j+(num>0?1:0))][int(k|(num<cur?1:0))] << endl;
				}
			}
		}
	}
	//cout << dp[n][K][0] << ' ' << dp[n][K][1] << endl;
	sum += dp[n][K][0] + dp[n][K][1];
	cout << sum << endl;
}	
