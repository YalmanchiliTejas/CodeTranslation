//  Copyright © 2020 Kavish Lodha. All rights reserved.
#include <bits/stdc++.h>
using namespace std;
#define vll vector<long long>
#define mll map<long long,long long>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
#define pb push_back
#define prll pair<long long,long long>
typedef long long ll;
typedef long double ld;
#define rep(i,a,n)   for(ll i=a; i<n; i++)
#define rrep(i,a,n)  for(ll i=n-1; i>=a; i--)
typedef map<string,ll> msl;
#define mx 100001
#define mod 1000000007
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll extgcd(ll a,ll b,ll& x,ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
ll revrsno(ll n){
    ll k=0;
    vll z;
    while(n>0){
        z.pb(n%10);
        n/=10;
    }
    rep(i,0,z.size()) k=k*10+z[i];
    return k;
}
bool isPrime(ll n){
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}
bool isPowerOfTwo(ll n) { 
   if(n==0) 
   return false; 
   return (ceil(log2(n)) == floor(log2(n))); 
}
ll powm(ll a,ll b) {
	ll res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}
ll divide(ll a,ll b) {
	return (a % mod) * powm(b, mod - 2) % mod;
}
ll mul(ll a,ll b) {
	return ((a % mod) * (b % mod)) % mod;
}
 
ll add(ll a,ll b) {
	return (a % mod + b % mod) % mod;
}
ll Totfun(ll n){
    ll z=n;
    if(n%2==0){
        while(n%2==0){
            n/=2;
        }
        z/=2;
    }
    for(ll i=3;i<=sqrt(n);i+=2){
        if(isPrime(i)&&n%i==0){
          while(n%i==0){
            n/=i;
          }
        z-=z/i;  
        }
    }
    if(n>1){
        z-=z/n;
    }
    return z;
}
ll maxPrimeFactor(ll n) { 
    ll maxPrime=-1; 
    while(n%2==0){
        maxPrime=2; 
        n>>=1; 
    } 
    for (ll i=3;i<=sqrt(n);i+=2) { 
        while(n%i==0){ 
            maxPrime=i; 
            n=n/i; 
        } 
    } 
    if (n>2) maxPrime=n; 
    return maxPrime; 
} 
ll nCr(ll n,ll r){
    if(r>n||r<0) return 0;
    ll z=1;
    for(ll i=n-r+1;i<=n;i++){
        z*=i;
        z/=(i+r-n);
    }
    return z;
}
/*
vll a[mx];
ll l[mx],d[mx];
void dfs(ll x,ll y){
   l[x]=1; d[x]=y;
   for(ll i:a[x])
   if(!l[i])
   dfs(i,y+1);
}
void bfs(ll x){
    queue<ll> q;
    q.push(x);
    l[x]=1;
    d[x]=0;
    while(!q.empty()){
        ll cur=q.front();
        q.pop();
        for(ll i : a[cur]){
            if(1-l[i]){
                q.push(i);
                d[i]=d[cur]+1;
                l[i]=1;
            }
        }
    }
}
*/
 /*sort(a,a+n);
    ll d=1;
    vll z;
    for(ll i=1;i<n;i++){
    if(a[i]==a[i-1]){
        d++;
    }
    else{
            z.pb(d);
            d=1;
    }
    }
    z.pb(d);*/
int main(){
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);
   cout.tie(NULL);
   string s;
   cin>>s;
   if(s[0]==s[1]&&s[1]==s[2]) cout<<"No";
   else cout<<"Yes";
   return 0;
}