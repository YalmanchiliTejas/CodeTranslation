#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define Mid ((l+r)/2)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
#define file(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout);
const int maxn=1e5+5,mod=1e9+7,inf=0x3f3f3f3f;
int n,m,Q,K,T;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

signed main(){
    //file(a);
    n=read();
    if(n>=30)puts("Yes");
    else puts("No");


    return 0;
}
