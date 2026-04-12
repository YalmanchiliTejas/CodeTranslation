#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list> 
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<set>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define B begin()
#define E end()
#define S size()
#define m9 1000000007
#define endl "\n"
using namespace std;
 
 

 
ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}

ll powmod(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = powmod(x, y/2, m) % m; 
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
} 

 
ll mul_inv(ll a, ll b) {
    ll b0 = b, t, q;
    ll x0 = 0ll, x1 = 1ll;
    if (b == 1ll) return 1ll;
    while (a > 1ll) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0ll) x1 += b0;
    return x1;
}
 
 
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define pin(a) for(auto x:a)cout<<x<<" ";cout<<endl
#define fck(a) cout<<a;exit(0)
#define vvll vector<vector<ll> >
#define A(b) b.begin(),b.end()
#define vpi std::vector<pll>
#include <array>
#include <stack>
#define arr2 array<ll,2>
#define arr3 array<ll,3>
#define varr2 vector<array<ll,2> >
#define varr3 vector<array<ll,3> >
//include<bits/stdc++.h>
 
 
bool fa(vll &x,vll &y){return x[0]<y[0];}
bool fa1(vll &x,vll &y){return x[1]<y[1];}
bool f1(pll &x,pll &y){return x.second>y.second;}
bool f2(pll &x,pll &y){
    return x.first>y.first;
}
 
 
bool f3(ll &x,ll &y){
    return x>y; 
    }


const ll maxn=2e5+2;





int main()
{ fastio;
//freopen("input.txt, "r", stdin); 
//freopen("output.txt", "w", stdout);

ll n;cin>>n;
ll b[n];
ll ans=0;
forl(i,0,n)cin>>b[i];
ll c[n+1];
c[n]=0;
for(ll i=n-1;i>=0;i--){
    c[i]=c[i+1]+b[i];
    c[i]%=m9;
}
// pin(c);
forl(i,0,n){
    ll x=b[i]*c[i+1];
    x%=m9;
    ans+=x;
    ans%=m9;
}
    ans%=m9;
p1(ans);





return 0;
}





  





