/*
 * @Author: RBQRBQ
 * @Date: 2020-04-05 21:40:13
 * @LastEditors: RBQRBQ
 * @LastEditTime: 2020-04-05 22:01:15
 */
//ac代码 
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std; 
typedef long long ll;
const ll maxn =10000000+10;
const ll mod=998244353;
inline ll qpow(ll a, ll n, ll p)  
{
    ll ans = 1;
    while(n)
    {
        if(n & 1ll) 
		ans = ans * a % p;
        a = a * a % p;
        n >>= 1ll;
    }
    return ans;
}
ll A[maxn+10];
ll B[maxn+10];

void exPower( int b, int p, int & a, int & k ) {
    if( p == 0 ) {
        a = 1; k = 0;
        return;
    }
    exPower( p, b % p, k, a );
    k -= b / p * a;
    return;
} 
int inv( int b, int p ) {
    int a, k;
    exPower( b, p, a, k );
    if( a < 0 ) a += p;
    return a;
}
void init( int n ) {
    A[ 0 ] = 1;
    for( int i = 1; i <= n; ++i ) A[ i ] = A[ i - 1 ] * i % mod;
    B[ n ] = inv( A[ n ], mod );
    for( int i = n - 1; i >= 0; --i ) B[ i ] = B[ i + 1 ] * ( i + 1 ) % mod;
    return;
}
inline ll C(ll a, ll b)
{
    if(a < b)
        return 0;
    return (A[a] * B[b] %mod)*B[a-b]%mod;
}
ll mul(ll x,ll y)
{
    return (x*y)%mod;
}
ll add(ll x,ll y)
{
    return (x+y>=mod)?x+y-mod:x+y;
}
ll pre[maxn];
int  main()
{
    int N;
    cin>>N;
    ll ans=qpow(3,N,mod);
    init(maxn);
    ll pos=0;
    pre[0]=1ll;
    for(int i=1;i<=N/2-1;i++)
    {
        pre[i]=mul(pre[i-1],2);
    }
    for(int i=1;i<=N/2;i++)
    {
        //pos=(pos%mod+(qpow(2,(N/2-i),mod)*C(N,N/2+i))%mod)%mod;
        pos=add(pos,mul(pre[N/2-i],C(N,N/2+i)));
    }
    pos=pos*2%mod;
    cout<<(ans-pos+mod)%mod;
}