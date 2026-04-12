#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define pf push_front
#define st first
#define nd second
#define sz(x) ((int)x.size())
#define ins insert
#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define lowbit(x) ((x)&(-x))
#define pi acos(-1.0)
using namespace std;

const int maxn=2e5+10;
const int maxe=1e6+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

inline int read(){
    int x=0; bool flag=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
    while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
    if(flag) return x;
    return ~(x-1);
}
inline void write(int x){
    if(x<0) {x=~(x-1); putchar('-');}
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

int a[maxn];
int sum[maxn]={};
main(){
    fastio;
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=n;i>=1;--i)sum[i]=(sum[i+1]+a[i])%mod;
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=(ans+(a[i]*sum[i+1])%mod)%mod;
    }
    cout<<ans<<endl;
}
