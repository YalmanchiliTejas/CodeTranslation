#include <bits/stdc++.h>

using namespace std;

typedef long long lo;
typedef pair< lo,lo > PII;

#define fi first
#define se second
#define mp make_pair
#define int long long
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)

const lo MAX = -1000000000000000000;
const lo MIN = 1000000000000000000;
const lo inf = 100000000000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 3005;
const lo mod = 1000000007;

int n,m,b[li],a[li],k,flag,t,dp[li][li][4];
int cev;
string s;
vector<int> v;

inline int f(int l,int r,int kim){
	int cevv=0;
	if(kim==0)cevv=-inf;
	else cevv=inf;
	if(l>r)return 0;
	if(~dp[l][r][kim])return dp[l][r][kim];
	if(kim==0){
		cevv=max(cevv,f(l+1,r,!kim)+a[l]);
		cevv=max(cevv,f(l,r-1,!kim)+a[r]);
	}
	else{
		cevv=min(cevv,f(l+1,r,!kim)-a[l]);
		cevv=min(cevv,f(l,r-1,!kim)-a[r]);
	}
	return dp[l][r][kim]=cevv;
}

main(void){
	memset(dp,-1,sizeof(dp));
	scanf("%lld",&n);
	FOR{
		scanf("%lld",&a[i]);
	}
	printf("%lld\n",f(1,n,0));
	return 0;
}
