#include <bits/stdc++.h>
using namespace std;
#define N 3010
int S[N][N],C[N][N];
inline int read() {
    int x=0;
    char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
int mod=0;
inline int pls(int x,int y) {
    int w=x+y;
    return w>=mod?w-mod:w;
}
inline void add(int &x,int y) {
    x+=y;
    if (x<0) x+=mod;
    if (x>=mod) x-=mod;
}
inline int tim(int x,int y) {
    long long w=1LL*x*y;
    return w>=mod?w%mod:w;
}
inline void mul(int &x,int y) {
    long long w=1LL*x*y;
    x=(w>=mod?w%mod:w);
}
inline int _pow(int x,int y,int p) {
    long long ans=1;
    while (y) {
        if (y&1) ans=ans*x%p;
        x=1LL*x*x%p,y>>=1;
    }
    return ans;
}
int main() {
    int n=read();mod=read();
    S[0][0]=C[0][0]=1;
    for (int i=1;i<=n+1;i++) {
        C[i][0]=1;
        for (int j=1;j<=n+1;j++) {
            C[i][j]=pls(C[i-1][j],C[i-1][j-1]);
            S[i][j]=pls(S[i-1][j-1],tim(j,S[i-1][j]));
        }
    }
    int w=-1,Ans=0;
    for (int i=0;i<=n;i++) {
        w*=-1;
        int ans=0;
        int Pow=_pow(2,n-i,mod),p=1;
        for (int j=0;j<=i;j++) {
            add(ans,tim(S[i+1][j+1],p)),mul(p,Pow); 
        }
        mul(ans,tim(C[n][i],_pow(2,_pow(2,n-i,mod-1),mod)));
        add(Ans,ans*w);
        // printf("%d\n",_pow(2,Pow,mod-1));
        // printf("%d ",ans*w);
    }// puts("");
    cout<<Ans<<endl;
    return 0;
}