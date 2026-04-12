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
const lo li = 10002;
const lo mod = 1000000007;

int n,m,b[li],a[li],k,flag,t,dp[li][102][4];
int cev;
string s;
vector<int> v;

inline int add(int x,int y){
	if(x+y>=mod)return x+y-mod;
	return x+y;
}

inline int f(int sira,int md,int ku){
	int cevv=0;
	if(sira>m)return 0;
	if(sira==-1){
		if(md)return 0;
		return 1;
	}
	if(sira==m){
		//~ cout<<md<<endl;
		if(md!=0)return 0;
		if(ku==0 || ku==1)return 1;
		return 0;
	}
	if(~dp[sira][md][ku])return dp[sira][md][ku];
	if(sira==0){
		int yes=m+1;
		if(sira<=m-2)yes=-1;
		for(int i=1;i<=9;i++){
			if(i<s[sira]-'0'){
				cevv=add(cevv,f(sira+1,(md+i)%n,(ku==0?1:ku)));
				cevv=add(cevv,f(yes,(md+i)%n,(ku==0?1:ku)));
			}
			if(i==s[sira]-'0'){
				cevv=add(cevv,f(sira+1,(md+i)%n,ku));
				cevv=add(cevv,f(yes,(md+i)%n,ku));
			}
			if(i>s[sira]-'0'){
				cevv=add(cevv,f(sira+1,(md+i)%n,(ku==0?2:ku)));
				cevv=add(cevv,f(yes,(md+i)%n,(ku==0?2:ku)));
			}
		}
	}
	else{
		int yes=m+1;
		if(sira<=m-2)yes=-1;
		for(int i=0;i<=9;i++){
			if(i<s[sira]-'0'){
				cevv=add(cevv,f(sira+1,(md+i)%n,(ku==0?1:ku)));
				cevv=add(cevv,f(yes,(md+i)%n,(ku==0?1:ku)));
			}
			if(i==s[sira]-'0'){
				cevv=add(cevv,f(sira+1,(md+i)%n,ku));
				cevv=add(cevv,f(yes,(md+i)%n,ku));
			}
			if(i>s[sira]-'0'){
				cevv=add(cevv,f(sira+1,(md+i)%n,(ku==0?2:ku)));
				cevv=add(cevv,f(yes,(md+i)%n,(ku==0?2:ku)));
			}
		}
	}
	return dp[sira][md][ku]=cevv;
}

main(void){
	fio();
	memset(dp,-1,sizeof(dp));
	cin>>s>>n;
	m=s.size();
	cout<<f(0,0,0);
	return 0;
}
