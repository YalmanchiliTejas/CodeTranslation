#include <bits/stdc++.h>
#define il inline
#define ll long long
const int N=105,P=1e9+7;

int n,h[N],A=1;
struct node{int a,b;}B;

il int ksm(int a,int b)
{
    int res=1;
    for ( ; b; b>>=1,a=(ll)a*a%P) if (b&1) res=(ll)res*a%P;
    return res;
}

il node sol(int l,int r,int x)
{
    node t; int i,cnt,mn=1e9+1,a=1,b=1,L=0,R=r-l+1;
    for (i=l; i<=r; i++)
        if (h[i]<mn) mn=h[i],cnt=1;
        else if (h[i]==mn) cnt++;
    if (cnt==R) return (node){(ksm(2,R)-2+P)%P,ksm(2,mn-x-1)};
    for (i=l; i<r+2; i++)
         if (!L&&h[i]>mn) L=i;
         else if (L&&(h[i]<=mn||i>r))
         {
             R-=i-L,t=sol(L,i-1,mn),L=0;
             a=(ll)a*(t.a+4ll*t.b)%P,b=2ll*b*t.b%P;
         }
    a=(a-b+P)%P;
    return (node){((ll)a*ksm(2,R)+(ll)b*(ksm(2,R)-2+P))%P,(ll)b*ksm(2,mn-x-1)%P};
}

int main()
{
    scanf("%d",&n); int i;
    for (i=1; i<=n; i++) scanf("%d",h+i);
    if (n==1) return printf("%d",ksm(2,h[1])),0;

    for (i=1; i<=n; i++) if (h[i]>h[i-1]&&h[i]>h[i+1])
        A=(ll)A*ksm(2,h[i]-std::max(h[i-1],h[i+1]))%P,h[i]=std::max(h[i-1],h[i+1]);
    B=sol(1,n,0),printf("%d",(ll)A*(B.a+2ll*B.b)%P);

    return 0;
}