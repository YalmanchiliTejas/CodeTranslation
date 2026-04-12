#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MOD 1000000007

char s[10005];int n,d;
int dp[10005][105][2];

int f(int k, int t, int e){
	int& r=dp[k][t][e];
	if(r>=0)return r;
	if(k==n)return r=t==0;
	r=0;
	fore(i,0,10){
		if(e&&i>s[k])break;
		r+=f(k+1,(t+i)%d,e&&i==s[k]);
		if(r>=MOD)r-=MOD;
	}
	return r;
}

int main(){
	scanf("%s%d",s,&d);n=strlen(s);
	fore(i,0,n)s[i]-='0';
	mset(dp,-1);
	printf("%d\n",(f(0,0,1)+MOD-1)%MOD);
	return 0;
}