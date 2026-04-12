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

const int MAXCYCLEN=200000;
const int MAXSLEN=200000;
const int MOD=1000000007;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int cyclen,slen;
char s[MAXSLEN+1];

int dp[MAXCYCLEN+1];
int dpsum[MAXCYCLEN+1];

int calcunlim() {
	memset(dp,0,sizeof(dp));
	dp[0]=dpsum[0]=1;
	FORE(i,1,cyclen) {
		if(i>=2) inc(dp[i],dpsum[i-2]);
		dpsum[i]=dp[i]; if(i-1>=0) inc(dpsum[i],dpsum[i-1]);
	}
	int ret=1;
	inc(ret,dp[cyclen]);
	for(int j=1;j+1<=cyclen;++j) inc(ret,(ll)j*dp[cyclen-(j+1)]%MOD);
	return ret;
}

int calclim(int lim) {
	//printf("lim=%d\n",lim);
	memset(dp,0,sizeof(dp));
	dp[0]=dpsum[0]=1;
	FORE(i,1,cyclen) {
		if(i%2==0) {
			// dp[i]+=dp[i-2]+dp[i-4]...+dp[i-(lim+1)]
			inc(dp[i],dpsum[i-2]);
			if(i-(lim+1)-2>=0) inc(dp[i],MOD-dpsum[i-(lim+1)-2]);
			//for(int j=1;j<=lim;j+=2) if(j+1<=i) inc(dp[i],dp[i-(j+1)]);
		}
		dpsum[i]=dp[i]; if(i-2>=0) inc(dpsum[i],dpsum[i-2]);
	}
	//printf("dp:"); REPE(i,cyclen) printf(" %d",dp[i]); puts("");
	int ret=dp[cyclen];

	for(int j=1;j<=lim&&j+1<=cyclen;j+=2) inc(ret,(ll)j*dp[cyclen-(j+1)]%MOD);
	//FORE(k,1,lim) FORE(j,k,lim) if(j+1<=cyclen&&j%2==1) inc(ret,dp[cyclen-(j+1)]);
	return ret;
}

int solve() {
	if(s[0]=='B') REP(i,slen) s[i]=s[i]=='B'?'R':'B';
	vector<int> seglen;
	for(int l=0,r=l;l<slen;l=r) {
		while(r<slen&&s[r]==s[l]) ++r;
		if(s[l]=='R'&&r<slen) seglen.PB(r-l);
	}
	//printf("seglen:"); REPSZ(i,seglen) printf(" %d",seglen[i]); puts("");
	if(SZ(seglen)==0) return calcunlim();
	int lim=INT_MAX;
	if(seglen[0]%2==0) lim=min(lim,seglen[0]+1); else lim=min(lim,seglen[0]);
	FORSZ(i,1,seglen) if(seglen[i]%2==1) lim=min(lim,seglen[i]);
	return calclim(lim);
}

void run() {
	scanf("%d%d",&cyclen,&slen);
	scanf("%s",s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}
