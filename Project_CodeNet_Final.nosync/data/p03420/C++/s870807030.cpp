#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;++i)
using namespace std;
int read(){
    int x=0,l=1; char ch=getchar();
    while(!isdigit(ch)) {if (ch=='-') l=-1; ch=getchar();}
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return x*l;
}
int main(){
    int n=read(),k=read(),x,y; long long ans=0;
    For(i,k+1,n){
        x=n/i; y=n%i; ans+=(long long)x*(i-k);
        if (y>=k){
            ans+=y-k; if (k) ++ans;
        }
    }
    printf("%lld\n",ans);
    return 0;
}