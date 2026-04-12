#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+5;
ll n;
int m;
ll a[N],s[N];
int pos[N];
int main(){
    // freopen("a.in","r",stdin);
    // int T;scanf("%d",&T);for(int tttt=1;tttt<=T;tttt++){
    if(1){
    scanf("%lld%lld%d",&n,&a[1],&m);
    s[1]=a[1];
    int cirpos,cirlen;
    for(int i=2;;i++){
        a[i]=a[i-1]*a[i-1]%m;
        s[i]=s[i-1]+a[i];
        if(pos[a[i]]){
            cirpos=pos[a[i]];
            cirlen=i-cirpos;
            break;
        }
        pos[a[i]]=i;
    }
    if(n<cirpos+cirlen){
        printf("%lld\n",s[n]);
    }
    else{
        long long ans=s[cirpos-1];
        n-=cirpos-1;
        ans+=(s[cirpos+cirlen-1]-s[cirpos-1])*(n/cirlen);
        ans+=s[cirpos+n%cirlen-1]-s[cirpos-1];
        printf("%lld\n",ans);
    }
    }return 0;
}
