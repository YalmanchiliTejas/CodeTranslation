#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int mod = 1000000007;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}
const int N = 200020;
int n,m,dp[N] = {0},sudp[N] = {0};
char ch[N];
int ans = 0;
int main() {
	read(n);read(m);
	scanf("%s",ch);
	int ftt = 0,clen = 0;
	for(int i=1;i<m;i++){
		if(ch[i]!=ch[0]){
			ftt = i;
			break;
		}
	}
	if(ftt){
	
		clen = (ftt%2)?(ftt):(ftt+1);
		int la = ftt;
		//cout<<clen<<endl;
		for(int i=ftt+1;i<m-1;i++){
			if(ch[i]==ch[0] && ch[i+1]!=ch[0]){
				//cout<<"OC "<<i<<' '<<la<<endl;
				if((i-la)%2) clen = min(clen,i-la);
			}
			if(ch[i]!=ch[0])la = i;
		}
		
	}
	int clim = (clen+1)/2;
	//cout<<ftt<<' '<<clen<<' '<<clim<<endl;
	dp[0] = sudp[0] = 1;
	for(int i=1;i<=n;i++){
		dp[i] = sudp[i-1];
		if(i-clim-1>=0)dp[i] = sub(dp[i],sudp[i-clim-1]);
		sudp[i] = add(sudp[i-1],dp[i]);
	}
	if(ftt == 0){
		ans = 0;
		dp[1] = sudp[1] = 1;
		dp[2] = sudp[2] = 1;
		ans = n+1;
		for(int i=3;i<n;i++){
			dp[i] = sudp[i-2];
			sudp[i] = add(sudp[i-1],dp[i]);
			ans = add(ans,mul(dp[i],n-i+1));
		}
		if(n == 1)ans = 1;
		cout<<ans<<endl;
		return 0;
	}
	if(n%2){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=min(clen+1,n);i++){
		int cl = (n-clen-1)/2,cr = (n-i)/2;
		if(n-2*cl-1>clen)cl+=1;
		if(i == 1 && i+cr*2 == n)cr-=1;
		if(cr<cl)continue;
		//cout<<i<<' '<<i+cl*2<<' '<<i+cr*2<<' '<<ans<<endl;
		ans = add(ans,sudp[cr]);
		if(cl>0) ans = sub(ans,sudp[cl-1]);
	}
	cout<<ans<<endl;
	return 0;
}
