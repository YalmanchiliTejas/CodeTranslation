#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=10000;
const int MAXMLT=100;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

char s[MAXLEN+1]; int slen;
int mlt;

int dp[MAXLEN+1][MAXMLT][2];

int solve() {
	memset(dp,0,sizeof(dp)); inc(dp[0][0][1],1);
	REP(i,slen) REP(j,mlt) REP(k,2) {
		REP(dig,10) {
			if(k==1&&dig>s[i]-'0') continue;
			int nk=k==1&&dig==s[i]-'0'?1:0;
			int nj=(j+dig)%mlt;
			inc(dp[i+1][nj][nk],dp[i][j][k]);
		}
	}
	int ret=MOD-1; REP(k,2) inc(ret,dp[slen][0][k]); return ret;	
}

void run() {
	scanf("%s",s); slen=strlen(s);
	scanf("%d",&mlt);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
