#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1009;
const int M=100009;
int n;ll a[N],pri[M];
int f[M],tot;
void init(){
    memset(f,0,sizeof(f));f[1]=1;
    for(int i=2;i<=M-9;i++){
        if(!f[i]) pri[++tot]=i;
        for(int j=1;j<=tot&&pri[j]*i<=M-9;j++){
            f[pri[j]*i]=1;
            if(i%pri[j]==0) break;
        }
    }
    return ;
}
int main(){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        ll t=a[i];
        for(int j=1;j<=tot;j++)
            if(t%pri[j]==0){
                while(!(t%pri[j])) t/=pri[j];
                if(t<M-9) break;
            }
        if(t>M-9) pri[++tot]=t;    
    }
    ll ans=0;
    for(int i=1;i<=tot;i++){
        ll area=0;
        for(int j=1;j<=n;j++)
            if(a[j]%pri[i]==0) area+=a[j];
        ans=max(ans,area);    
    }
    printf("%lld\n",ans);
    return 0;
}
