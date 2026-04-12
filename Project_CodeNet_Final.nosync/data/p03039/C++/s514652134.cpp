#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int N = 2e5+5;
const int mod = 1e9+7;
 
int add(int x,int y) {
    int ret = (x+y)%mod;
    if(ret<0) {
        ret += mod;
    }
    return ret;
}
int mul(int x,int y) {
    ll ret = (ll)x*y;
    ret %=mod;
    return ret;
}
int myPow(int x,int k) {
    int ret = 1;
    while(k>0) {
        if(k&1) {
            ret = mul(ret, x);
        }
        x = mul(x,x);
        k/=2;
    }
    return ret;
}
 
int in[N],fac[N];
 
int combi(int n,int k) {
    int ret = fac[n];
    ret = mul(ret, myPow(fac[k],mod-2));
    ret = mul(ret, myPow(fac[n-k],mod-2));
    return ret;   
}
void solve() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    fac[0]=  1;
    for(int i=1;i<N;++i) {
        fac[i] = mul(fac[i-1],i);
    }
    int mm =  combi(n*m-2,k-2);
    int sum = 0,tmp=0,cc = 0;
    for(int i=1;i<=n;++i) {
        int x = add(mul(cc,i),-tmp); 
        ++cc;
        tmp = add(tmp,i);
        x = mul(x, mul(m,m));
        sum = add(sum,x);
    }
    cc = 0, tmp = 0;
    for(int i=1;i<=m;++i) {
        int x = add(mul(cc,i),- tmp);
        ++cc;
        tmp = add(tmp,i);
        x = mul(x,mul(n,n));
        sum = add(sum,x);
    }
    sum = mul(sum, mm);
    printf("%d\n", sum);
}
 
int main()
{
    //freopen("input.txt","r",stdin);
    solve();
}