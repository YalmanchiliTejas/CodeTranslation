#include <bits/stdc++.h>
const int MAXN=1e5+10;
#define ll long long
using namespace std;
ll readll(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int readint(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return f*x;
}
int num[MAXN];
int main(){
    int n;int k;n=readint();k=readint();
    ll ans=0;
    for(int i=k+1;i<=n;i++){
        if(n%i){
            ll tt=n/i;ans+=tt*(i-k);
            if(n%i>=k){
                if(k) ans+=n%i-k+1;
                else ans+=n%i;
            }
        }
        else{
                ll t=n/i;
                ans+=(i-k)*t;
            }
    }
    printf("%lld\n",ans);
    return 0;
}