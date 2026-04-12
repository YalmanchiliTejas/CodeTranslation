#include<bits/stdc++.h>
#define ll long long

ll n,x,b[50],p[50];

ll c(ll n,ll x){
    if(n==0)return 1;
    if(x==0||x==1)return 0;
    else if(x<=1+b[n-1])return c(n-1,x-1);
    else if(x==2+b[n-1])return 1+p[n-1];
    else if(x<=2+2*b[n-1])return 1+p[n-1]+c(n-1,x-2-b[n-1]);
    else if(x==3+2*b[n-1])return p[n-1]*2LL+1;
}

int main(){
    scanf("%lld %lld",&n,&x);
    b[0]=1;
    p[0]=1;
    for(int i=1;i<50;i++)p[i]=2*p[i-1]+1,b[i]=2*b[i-1]+3;
    printf("%lld\n",c(n,x));
}