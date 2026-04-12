#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
LL a,b,x;
LL MOD=1e9+7;
int main(){
	cin>>a>>b>>x;
	if(x<a){
		cout<<x%MOD<<endl;
	}else{
		x-=a;
		LL ans=0;
		LL now=x/(a-b);
		ans+=(now%MOD)*(a%MOD);
		ans%=MOD;
		//cout<<ans<<endl;
		x=x%(a-b);
		x+=a;
		//cout<<x<<endl;
		while(x>=a){
			x-=a;
			x+=b;
			ans+=a;
		}
		ans+=x;
		ans%=MOD;
		cout<<ans<<endl;
	}
}
