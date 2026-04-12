#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;

#define ft first
#define sd second
#define flag bool fl=true

#define mod 1000000007
#define N 10000001
#define MX 1000000001
#define MXX 1000000000000000001

#define pb push_back
#define fa(n) for(int i=0;i<n;i++)
#define fa1(n) for(int i=1;i<=n;i++)
#define fab(i, a, b) for(int i=a;i<=b;i++)
#define cs cout<<"Case "<<qq<<": "
#define csl cout<<"Case "<<qq<<":"<<endl;
#define T int tt, qq=0; cin>>tt; while(qq++<tt)
#define fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define ina(array, size) for(int i=0;i<size;i++) cin>>array[i];
#define outa(array, size) for(int i=0;i<size;i++) cout<<array[i]<<" ";
#define outla(array, size) for(int i=0;i<size;i++) cout<<array[i]<<endl;

#define deg(rad) (rad*180.0)/pi
#define pi acos(-1)
#define log(n) (int)log2(n)
#define logg(a)(b) log(b)/log(a)

int main()
{
    ll n, sum=0;
    cin>>n;

    ll a[n], cum[n]={};
    for(int i=0;i<n;i++) cin>>a[i];

    cum[0]=a[0]%mod;
    for(int i=1;i<n;i++) cum[i]=(a[i]+cum[i-1])%mod;

    for(int i=1;i<n;i++) sum+=(cum[i-1]*a[i])%mod;
    cout<<sum%mod;
}


/*

//----------useful_functions----------

long long extended_euclid(ll a, ll b, ll &x, ll &y) //ax+by=c
{
    if(b==0)
    {
        x=1, y=0;
        return a;
    }

    ll x1, y1;
    ll d=extended_euclid(b, a%b, x1, y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

long long bigMod(ll a, ll b) //(a^b)%mod
{
    ll ans=1;
    while(b)
    {
        if(b%2==1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ans%mod;
}

long long modInverse(ll a, ll b) //a*x=1 mod b
{
    ll x, y;
    ll gcd=extended_euclid(a, b, x, y);

    if(gcd==1) return ((x%b)+b)%b;
    else return 1;
}

long long nCr(ll n, ll r) //n<=1e6
{
    //declare globally-> ll fact[1000001];
    fact[1]=1;
    for(ll i=2; i<1000001; i++)
        fact[i]=(i*fact[i-1])%mod;

    return (fact[n]*modInverse(fact[r], mod)*modInverse(fact[n-r], mod))%mod;
}

long long josephus(ll n, ll k) //k'th person is killed out of n in the circle
{
    if(n==1) return 1;
    else return (josephus(n-1, k)+k-1)%n+1;
}

bool fl[N+1];
vector<ll> sieve(ll n)
{
    vector<ll> primes;
    for(ll i=3; i*i<=n; i+=2)
        for(ll j=i*i; j<=n; j+=i+i)
            fl[j]=true;

    primes.pb(2);
    for(ll i=3; i<=n; i+=2) if(!fl[i]) primes.pb(i);
    return primes;
}
vector<ll> p=(sieve(N));

ll eulerTotient(ll x)
{
    db ans=x;
    for(int i=0; i<p.size() && p[i]*p[i]<=x; i++)
    {
        if(x%p[i]==0)
        {
            ans*=(1.0-(1/(db)p[i]));
            while(x%p[i]==0) x/=p[i];
        }
    }
    if(x>1) ans*=(1.0-(1/(db)x));

    return ans;
}

*/
