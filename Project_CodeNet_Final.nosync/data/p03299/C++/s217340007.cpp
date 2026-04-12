#include <bits/stdc++.h>
using namespace std;
const int N=150,mo=1e9+7;
int fap(int a,int b){
    if (b<=0) return 1;
    int s=1;
    for (; b; b>>=1,a=1ll*a*a%mo)
	if (b&1) s=1ll*s*a%mo;
    return s;
}
void cal(int &x,int y){
    (x+=y)%=mo; return;
}
int n,h[N],a[N],f[N][N];
int main(){
    cin>>n;
    for (int i=1; i<=n; ++i)
	cin>>h[i],a[i]=h[i];
    int tmp=n;
    sort(a+1,a+n+1);
    tmp=unique(a+1,a+n+1)-a-1;
    for (int i=1; i<=n; ++i)
	h[i]=lower_bound(a+1,a+tmp+1,h[i])-a;
    f[0][0]=1;
    for (int i=1; i<=n; ++i){
	f[i][0]=f[i-1][0]*2%mo;
	for (int j=h[i]+1; j<=h[i-1]; ++j)
	    cal(f[i][0],f[i-1][j]*2%mo);
	tmp=fap(2,a[h[i]]-a[h[i-1]]);
	for (int j=min(h[i],h[i-1]); j; --j)
	    cal(f[i][j],1ll*tmp*f[i-1][j]%mo);
	for (int j=h[i-1]+1; j<=h[i]; ++j){
	    if (j==1)
		cal(f[i][j],1ll*f[i-1][0]*(fap(2,a[1])-2)%mo*fap(2,a[h[i]]-a[j])%mo);
	    else
		cal(f[i][j],2ll*f[i-1][0]*(fap(2,a[j]-a[j-1])-1)%mo*fap(2,a[h[i]]-a[j])%mo);
	}
    }
    int ans=0;
    for (int i=0; i<=h[n]; ++i)
	cal(ans,f[n][i]);
    cout<<ans;
    return 0;
}
