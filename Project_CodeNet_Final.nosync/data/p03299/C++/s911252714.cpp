#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#define LL long long
#define LD long double
using namespace std;
const int NN=100 +117;
const int MM=100 +117;
int read(){
	int fl=1,x;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-'){fl=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}
void open(){
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}


int m,n;
LL a[NN]={};
LL dp[NN][NN]={};
bool conti[NN]={};
int li[NN]={};
const int mod=1e9+7;
LL ksm(LL a,LL b){
	LL ret=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)ret=ret*a%mod;
	return ret;
}
int main(){
	//open();
	n=read();
	LL ans=1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]==1){
			ans=ans*2%mod;
			a[i]=0;
		}
	}
	int lcnt=0;
	for(int i=1;i<=n;++i){
		int nb=max(a[i-1],a[i+1]);
		if(a[i]>nb){
			ans=ans*ksm(2,a[i]-nb)%mod;
			a[i]=nb;
		}
		if(a[i])li[++lcnt]=a[i];
	}
	sort(li+1,li+1+lcnt);
	lcnt=unique(li+1,li+1+lcnt)-li-1;
	for(int i=1;i<=n+1;++i){
		if(!a[i]){
			conti[i]=0;
			if(conti[i-1]==1){
				ans=ans*dp[i-1][0]%mod;
			}
		}
		else{
			int h=lower_bound(li+1,li+1+lcnt,a[i])-li;
			if(conti[i-1]){
				int pre=lower_bound(li+1,li+1+lcnt,a[i-1])-li;
				if(pre<=h){
					for(int j=0;j<=pre;++j){
						dp[i][j]=(dp[i-1][j]+dp[i-1][pre])*ksm(2,a[i]-a[i-1])%mod;
					}
					for(int j=pre+1;j<=h;++j){
						dp[i][j]=(dp[i-1][pre]+dp[i-1][pre])*ksm(2,a[i]-li[j])%mod;
					}
				}
				else{
					for(int j=0;j<=h;++j){
						dp[i][j]=(dp[i-1][j]+dp[i-1][h])%mod;
					}
				}
			}
			else{
				dp[i][0]=ksm(2,a[i]);
				for(int j=1;j<=h;++j){
					dp[i][j]=2*ksm(2,a[i]-li[j]);
				}
			}
			conti[i]=1;
		}
	}
	printf("%lld\n",ans);
	close();
	return 0;
}