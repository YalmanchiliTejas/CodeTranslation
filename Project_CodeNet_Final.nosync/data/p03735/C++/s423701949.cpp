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
//#define inf 0x3f3f3f3f
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
typedef vector<int> vi;
ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p%mod;p=p*p%mod;q>>=1;}return f;}
//int n,m,k,t,a[maxn],b[maxn],id[maxn],ama,bma,ami=1e9,bmi=1e9,dma,dmi=1e9;
//bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
    int n;
    scanf("%d",&n);
    vector<ll> a(n), b(n), di(n);
    ll maxa = 0, maxb = 0, mina = INT_MAX, minb = INT_MAX;
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
        if(a[i] > b[i]) swap(a[i], b[i]);
        di[i] = i;
        maxa = max(maxa, a[i]);
        maxb = max(maxb, b[i]);
        mina = min(mina, a[i]);
        minb = min(minb, b[i]);
    }
    ll res = (maxa - mina) * (maxb - minb);
    sort(di.begin(), di.end(), [&](ll n1, ll n2) {
        return a[n1] < a[n2];
    });
    ll dmin = INT_MAX, dmax = 0;
    for(int i = 0; i < n - 1; i++ ) {
        dmin = min(dmin, b[di[i]]);
        dmax = max(dmax, b[di[i]]);
        res = min(res, (max(dmax, a[di[n - 1]]) - min(dmin, a[di[i+1]]))* (maxb - mina));
    }
    printf("%lld\n", res);
    return 0;
}