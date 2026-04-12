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
#define rep(i,m,n) for(i=m;i<=(int)n;i++)
#define mod 1000000007
#define inf 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pi acos(-1.0)
#define pii pair<int,int>
#define ls rt<<1
#define rs rt<<1|1
#define sys system("pause")
const int maxn=2e5+10;
const int N=1e2+10;
using namespace std;
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p%mod;p=p*p%mod;q>>=1;}return f;}
int n,m,k,t,a[maxn];
int main()
{
    int i,j;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    for(i=n;i>=1;i-=2)printf("%d ",a[i]);
    i++;
    if(i<=0)i+=2;
    for(;i<=n;i+=2)printf("%d ",a[i]);
    return 0;
}
