//Bismillahirrahmanirrahim
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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
const lo inf = 1000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 3002;
const lo mod = 998244353;

int n,m,b[li],a[li],k,flag,t,dp[li][li][4];
int cev;
string s;
vector<int> v;

inline int add(int x,int y){
	if(x+y>=mod)return x+y-mod;
	return x+y;
}

inline int f(int sira,int topl,int bas){
	int cevv=0;
	if(topl<0)return 0;
	if(sira>n){
		if(topl==0)return 1;
		return 0;
	}
	if(~dp[sira][topl][bas])return dp[sira][topl][bas];
	if(bas==0){
		cevv=add(cevv,f(sira+1,topl,0));
		cevv=add(cevv,f(sira,topl,1));
	}
	else{
		cevv=add(cevv,f(sira+1,topl-a[sira],1));
		if(sira!=n)
		cevv=add(cevv,f(n+1,topl-a[sira],1));
		if(sira!=n)
		cevv=add(cevv,f(n+1,topl,1));
		cevv=add(cevv,f(sira+1,topl,1));
	}
	return dp[sira][topl][bas]=cevv;
}

main(void){
	memset(dp,-1,sizeof(dp));
	scanf("%lld %lld",&n,&k);
	FOR{
		scanf("%lld",&a[i]);
	}
	printf("%lld\n",f(1,k,0));
	return 0;
}

