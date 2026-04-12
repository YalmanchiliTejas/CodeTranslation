#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000000LL

typedef unsigned long long ll;

int n;
ll dp[1002];
string s[1002];
string utf[4][4] = {
	{"0xxxxxxx","","",""},
	{"110yyyyx","10xxxxxx","",""},
	{"1110yyyy","10yxxxxx","10xxxxxx",""},
	{"11110yyy","10yyxxxx","10xxxxxx","10xxxxxx"}
};

ll check(int idx,int len){
	ll res = 1;
	int xcnt = 0; //rbgp^[ÅyÌÊuÅ, üÍñªxÉÈÁÄ¢é
	int onecnt = 0; //rbgp^[ÅyÌÊuÅ, üÍñª1ÉÈÁÄ¢é

	for(int i=0;i<len;i++){
		for(int j=0;j<8;j++){
			char cu = utf[len-1][i][j];
			char cs = s[idx+i][j];

			if(cu == '0' || cu == '1'){
				if(cs != 'x' && cu != cs) return 0;
			}
			else if(cu == 'x'){
				if(cs == 'x') res = (res * 2) % MOD;
			}
			else{
				if(cs == 'x') xcnt++;
				else if(cs == '1') onecnt++;
			}
		}
	}

	if(len == 1) return res;
	if(onecnt==0 && xcnt==0) return 0;

	if(onecnt == 0) res = (res * ((1<<xcnt) - 1)) % MOD;
	else res = (res * (1<<xcnt)) % MOD;

	return res;
}

int main(void){
	while(cin>>n,n){
		for(int i=0;i<n;i++) cin>>s[i];

		memset(dp,0,sizeof(dp));
		dp[0] = 1;

		for(int i=0;i<n;i++){
			for(int j=1;j<=4;j++){
				if(i+j > n) break;
				ll pat = check(i,j);
				if(pat == 0) continue;
				dp[i+j] = (dp[i+j] + dp[i] * pat) % MOD;
			}
		}

		cout<<dp[n]<<endl;
	}

	return 0;
}