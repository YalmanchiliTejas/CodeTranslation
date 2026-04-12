#include<bits/stdc++.h>

#define ankit_2305 cerr<<"\nTime taken : "<<(float)(clock()-time_p)/CLOCKS_PER_SEC<<" sec\n";
#define START clock_t
#define TIMER time_p=clock();
#define ll long long

#define MOD 1000000007

using namespace std;

ll dp[101][4][11] = {}; 
string s;

void initdp(int n, int k){
	for(int i=0;i<=k;i++){
		for(int l=0;l<10;l++)
			if(i == 0)
				dp[1][i][l] = 1;
			else
				dp[1][i][l] = l;
	dp[1][i][10] = 9;
	}
}

ll solve(int n, int k, int l){
	
	if(k > n || n == 0){
		return 0;
	}
	
	if(k == 0){
		return 1;
	}
	
	if(dp[n][k][l] != 0){
		return dp[n][k][l];
	}
	
	
	ll res = 0;
	
	if(l > 0){
		res += solve(n-1, k, 10);
		res += (l-1)*solve(n-1, k-1, 10);
		if(l < 10)
			res += solve(n-1, k-1, int(s[(int)s.size() - n + 1] - '0'));
	}
	else
		res += solve(n-1, k, int(s[(int)s.size() - n + 1] - '0'));
	return dp[n][k][l] = res;
}

int main(){
    START TIMER
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int k;
	cin >> s >> k;
	const int n = s.size();	
	initdp(n, k);
	cout<<solve(n, k, int(s[0] - '0'));
    ankit_2305
    return 0;
}
