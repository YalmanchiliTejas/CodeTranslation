/*
  Motto - try hard to become an expert
*/
#include <bits/stdc++.h>
#include <map>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <iomanip>
 
//define
#define rep(i,n)    for(int i=0;i<n;i++)
#define repu(i,k,n) for(int i=k;i<=n;i++)
#define repd(i,k,n) for(int i=k;i>=n;i--)
#define se second
#define fi first
#define pb push_back
#define mp make_pair
#define INF (int)INT_MAX
#define all(v)  v.begin(), v.end()
#define endl "\n"
 
//typedef
typedef long long int ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::vector<int> vi;
typedef std::vector< pii > vii;
typedef std::vector< ll > vll;
typedef std::vector< std::pair < pii, int > > vpp;
 
const int N = 3*1e5 +5 ;
const long long MOD = 998244353;
const long long inf = 1e18;
 
using namespace std;
 
ll MAXN=100001;
ll spf[100001]; 
 
ll modpow(ll x,ll n){
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return res;
}
 
ll modFact(ll n, ll p) 
{ 
    if (n >= p) 
        return 0; 
  
    ll result = 1; 
    for (ll i = 1; i <= n; i++) 
        result = (result * i) % p; 
  
    return result;  
} 
 
bool isPrime(int x)
{
    if(x%2==0)
        return 0;
    for(int i=3;i<=sqrt(x);i+=2)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}
 

 
void solve()
{
	string s ; 
	cin>>s; 
	if(s=="AAA" || s=="BBB"){
		cout<<"No\n";
	}
	else{
		cout<<"Yes\n";
	}
    
}
 
int main() {
  
    int t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    } 
    
}