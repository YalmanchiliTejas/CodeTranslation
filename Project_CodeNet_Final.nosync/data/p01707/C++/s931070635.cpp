#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;
#define fir first
#define sec second
#define IINF INT_MAX
#define LINF LLONG_MAX
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define pque(type) priority_queue<type,vector<type>,greater<type> >
#define memst(a,b) memset(a,b,sizeof(a))
#define iter(v,ite) for(auto ite=(v).begin();ite!=(v).end();ite++)
#define mimunum(v,x) distance((v).begin(),lower_bound((v).begin(),(v).end(),x))

#define MOD ((lli)(1000000007))
lli mop(lli p,lli q){
	lli res=1,bp=p,b=1;
	while(q){
		if(q&b){
			res=(res*bp)%MOD;
			q-=b;
		}
		bp=(bp*bp)%MOD;
		b*=2;
	}
	return res;
}

lli inv(lli p){
	return mop(p,MOD-2);
}

lli fact(int p){
	lli res=1;
	reg(i,1,p)res=(res*i)%MOD;
	return res;
}

/*
lli comb(lli p,lli q){
	lli res=(((fact(p)*inv(fact(q)))%MOD)*inv(fact(p-q)))%MOD;
	return res;
}
*/

lli fdat[500005];

lli ifdat[500005];

void init(){
	{
		fdat[0]=fdat[1]=1;
		lli r=1;
		reg(i,1,500004){
			r=(r*i)%MOD;
			fdat[i] = r;
		}
	}

	{
		ifdat[0]=ifdat[1]=1;
		lli r=1;
		reg(i,1,500004){
			r=(r*inv(i))%MOD;
			ifdat[i] = r;
		}
	}
}

lli comb(lli p,int q){
	p%=MOD;
	lli res=1;
	rep(i,q)res=(res*(p-i))%MOD;
	res=(res*ifdat[q])%MOD;
	return res;
}


int n,x;
lli d;
lli dp[2005][4005];

int main(void){
	init();
	for(;;){
		scanf("%d%lld%d",&n,&d,&x);
		if(n==0)break;
		//printf("%d %lld %d\n",n,d,x);
		memset(dp,0,sizeof(dp));
		dp[0][n]=1;
		reg(i,1,n){
			lli ns=0;
			reg(j,1,x-1)ns=(ns+dp[i-1][j])%MOD;
			rep(j,n){
				dp[i][j]=ns;
				ns=(ns+dp[i-1][j+x])%MOD;
				ns=(ns-dp[i-1][j+1]+MOD)%MOD;
			}
		}
		lli ans=0;
		reg(i,1,n){
			if(i>d)break;
			lli na=(comb(d,i)*dp[i][0])%MOD;
			ans=(ans+na)%MOD;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}