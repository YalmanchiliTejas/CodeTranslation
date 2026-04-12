#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lg long long
#define db double
#define lb(x) ((x)&-(x))
#define ft first
#define sd second

#define HII cerr<<"HI"<<endl
#define LLLINE cerr<<"@@@@@@@@@@@@@@@@@@@@"<<endl

template <class _T_>
void read(_T_& d){
	d=0;int f=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f*=-1;
	for(;c>='0'&&c<='9';c=getchar())d=d*10+c-'0';
	d*=f;
}

/************************************************/
#define Md 1000000007
#define MN 200005
int n,m;
char c[MN];
lg Pow(lg x,lg y){
	lg res=1;for(;y;y>>=1,x=x*x%Md)if(y&1)res=res*x%Md;return res;
}
int Fix(int x){
	if(x<0)return x+Md;
	if(x>=Md)return x-Md;
	return x;
}
int dp[MN],tmp[MN];
int miu[MN];
int main(){
	read(n);read(m);
	scanf("%s",c+1);
	miu[1]=1;
	for(int i=1;i<MN;++i){
		for(int j=i+i;j<MN;j+=i){
			miu[j]-=miu[i];
		}
	}
	char Hd=c[1];
	int cnt=0,mx;
	for(int i=1;i<=m;++i){
		if(c[i]==Hd)++cnt;
		else break;
	}
	if(cnt&1)mx=cnt;else mx=cnt+1;
	if((n&1)&&cnt!=m)return puts("0"),0;
	if(cnt==m){
		int res=0;
		tmp[0]=1;
		dp[0]=1;
		if(n>=2)res=n;
		for(int i=1;i<n-1;++i){
			dp[i]=(i>=2?tmp[i-2]:0);
			tmp[i]=Fix(tmp[i-1]+dp[i]);
			res=Fix(res+1ll*dp[i]*(n-i)%Md);
		}
		printf("%d",res+1);
		return 0;
	}
	int res=(cnt==m);
	cnt=0;
	for(int i=1;i<=m;++i){
		if(c[i]==Hd)++cnt;
		else{
			if(!cnt)continue;
			if(cnt&1)mx=min(mx,cnt);
			cnt=0;
		}
	}
	//for(int i=1;i<=5;++i)cerr<<miu[i]<<' ';cerr<<endl;
	tmp[0]=tmp[1]=1;
	dp[0]=1;
	mx+=2;
	if(n<mx)res+=n;
	for(int i=2;i<=n;i+=2){
		dp[i]=Fix(tmp[i-1]-(mx>i?0:tmp[i-mx]));
		tmp[i]=tmp[i+1]=Fix(tmp[i-1]+dp[i]);
		//cerr<<dp[i]<<' '<<i<<endl;
		if((n-i)%2==0&&n-i<mx)res=Fix(res+1ll*dp[i]*(n-i)%Md);
	}
	cout<<res;
	return 0;
}
