#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int mod=(int)1e9+7,N=105;
int a[N],p[N],f[N][N];
void upd(int &x,int y){x=(x+y)%mod;}
int ksm(int x,int y){
    int tmp=x,ans=1;
    while(y){
        if(y&1) ans=(ll)ans*tmp%mod;
        tmp=(ll)tmp*tmp%mod;
        y>>=1;
    }
    return ans;
}
int main(){
    int n,i,len,j,k,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]),p[i]=a[i];
    p[n+1]=1;
    sort(p+1,p+n+2);
    len=unique(p+1,p+n+2)-p-1;
    for(i=1;i<=n;i++) a[i]=lower_bound(p+1,p+len+1,a[i])-p;
    j=1;
    for(j=1;j<a[1];j++)
        f[1][j]=(ll)(ksm(2,p[j+1]-p[j])-1)*ksm(2,p[a[1]]-p[j+1])%mod*2%mod;
    f[1][a[1]]=2;
    for(i=1;i<n;i++)
        for(j=1;j<=a[i];j++){
            if(a[i+1]<=a[i]){
                if(j>=a[i+1]) upd(f[i+1][a[i+1]],f[i][j]*2%mod);
                else upd(f[i+1][j],f[i][j]);
            }
            else{
                if(j==a[i]){
                    for(k=a[i];k<a[i+1];k++)
                        upd(f[i+1][k],(ll)f[i][j]*2*(ksm(2,p[k+1]-p[k])-1)%mod*ksm(2,p[a[i+1]]-p[k+1])%mod);
                    upd(f[i+1][a[i+1]],f[i][j]*2%mod);
                }
                else upd(f[i+1][j],(ll)f[i][j]*ksm(2,p[a[i+1]]-p[a[i]])%mod);
            }
        }
    for(j=1;j<=a[n];j++) upd(ans,f[n][j]);
    printf("%d",ans);
    return 0;
}
