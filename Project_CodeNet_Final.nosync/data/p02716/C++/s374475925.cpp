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
#define pb push_back
#define int long long
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)

const lo MAX = -1000000000000000000;
const lo MIN = 1000000000000000000;
const lo inf = 100000000000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 200005;
const lo mod = 1000000007;

int n,m,b[li],a[li],k,flag,t,dp[li][4][4];
int cev;
string s;
vector<int> v;

inline int f(int sira,int atla,int hak){
	int cevv=-inf;
	if(sira>n){
		if(hak)return -inf;
		return 0;
	}
	if(~dp[sira][atla][hak])return dp[sira][atla][hak];
	if(hak==1){
		cevv=max(cevv,f(sira+1,atla,0));
		if(atla==0)cevv=max(cevv,f(sira+1,1,1));
		if(atla==0)cevv=max(cevv,f(sira+1,1,0));
		cevv=max(cevv,f(sira+2,atla,1)+a[sira]);
	}
	else if(atla==1){
		cevv=max(cevv,f(sira+2,1,0)+a[sira]);
	}
	else{
		cevv=max(cevv,f(sira+1,1,0));
		cevv=max(cevv,f(sira+2,0,0)+a[sira]);
	}
	return dp[sira][atla][hak]=cevv;
}

main(void){
	memset(dp,-1,sizeof(dp));
	scanf("%lld",&n);
	//~ cout<<n%2<<endl;
	
	FOR scanf("%lld",&a[i]);
	if(n%2==0)cev=f(1,0,0);
	else cev=f(1,0,1);
	printf("%lld\n",cev);
	return 0;
}

