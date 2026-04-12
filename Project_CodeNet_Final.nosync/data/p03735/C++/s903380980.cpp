#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>
#include <ctime>
#define rep(i,m,n) for(i=m;i<=n;i++)
#define mod 1000000009
#define inf 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pi acos(-1.0)
#define pii pair<int,int>
#define sys system("pause")
const int maxn=2e5+10;
const int N=2e5+10;
using namespace std;
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p%mod;p=p*p%mod;q>>=1;}return f;}
int n,m,k,t,a[maxn],b[maxn],id[maxn],ama,bma,ami=1e9,bmi=1e9,dma,dmi=1e9;
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
    int i,j;
    scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%d%d",&a[i],&b[i]);
        if(a[i]>b[i])swap(a[i],b[i]);
        id[i]=i;
        ama=max(ama,a[i]);
        ami=min(ami,a[i]);
        bma=max(bma,b[i]);
        bmi=min(bmi,b[i]);
    }
    ll ret=(ll)(ama-ami)*(bma-bmi);
    sort(id+1,id+n+1,cmp);
    rep(i,1,n)
    {
        dma=max(dma,b[id[i]]);
        dmi=min(dmi,b[id[i]]);
        ret=min(ret,(ll)(max(dma,a[id[n]])-min(dmi,a[id[i+1]]))*(bma-ami));
    }
    printf("%lld\n",ret);
    return 0;
}