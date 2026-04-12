#include <bits/stdc++.h>
using namespace std;
const int N=3050;
int fap(int a,int b,int c){
    int s=1;
    for (; b; b>>=1,a=1ll*a*a%c)
	if (b&1) s=1ll*s*a%c;
    return s;
}
int s[N][N],c[N][N],mo,n;
int main(){
    cin>>n>>mo;
    for (int i=0; i<=n+1; ++i){
	c[i][0]=1,s[i][i]=1;
	for (int j=1; j<=i; ++j){
	    c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
	    s[i][j]=(1ll*s[i-1][j]*j+s[i-1][j-1])%mo;
	}
    }
    int ans=0,sum;
    for (int i=0; i<=n; ++i){
	sum=0;
	for (int j=1; j<=i+1; ++j)
	    (sum+=1ll*s[i+1][j]*fap(2,1ll*(j-1)*(n-i)%(mo-1),mo)%mo)%=mo;
	sum=1ll*c[n][i]*sum%mo*fap(2,fap(2,n-i,mo-1),mo)%mo;
	if (i&1) sum=mo-sum;
	(ans+=sum)%=mo;
    }
    cout<<ans;
    return 0;
}
