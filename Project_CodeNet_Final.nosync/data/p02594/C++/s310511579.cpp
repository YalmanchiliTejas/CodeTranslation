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
const long long MOD = 1e9 + 7;
const long long inf = 1e18;
 
using namespace std;
 

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
 
ll binomialCoeff(ll n, ll k) 
{ 
	ll C[n + 1][k + 1]; 
	ll i, j; 


	for (i = 0; i <= n; i++) 
	{ 
		for (j = 0; j <= min(i, k); j++) 
		{ 
			
			if (j == 0 || j == i) 
				C[i][j] = 1; 

			else
				C[i][j] = (C[i - 1][j - 1] + 
										C[i - 1][j])%MOD; 
		} 
	} 

	return C[n][k]; 
}
bool compare(const string &a , const string&b){
	
}
 
void solve()
{
	int n ; 
	cin>>n ;
	if(n>=30){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
}
 
int main() {
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    } 
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}