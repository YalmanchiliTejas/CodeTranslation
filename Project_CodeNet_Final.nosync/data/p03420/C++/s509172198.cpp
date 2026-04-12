#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
void File(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
}
#define REP(i,a,b) for(register int i=a;i<=b;++i)
#define DREP(i,a,b) for(register int i=a;i>=b;--i)
#define ll long long
ll n,k,ans;
int main(){
	//File();
	scanf("%lld%lld",&n,&k);
	if(k==0){
		cout<<n*n<<endl;
		return 0;
	}
	REP(i,k+1,n){
		ans+=n/i*(i-k);
		if(n%i)ans+=(n%i-k+1)>=0 ? n%i-k+1 : 0;
	}
	cout<<ans<<endl;
	return 0;
}
