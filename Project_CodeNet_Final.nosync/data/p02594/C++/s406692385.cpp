/*
Author : Aditya Gupta
Team : TechTurtle
Date : 02-06-2020
Time : 20:05:54
*/

 
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vll vector<ll>
#define vvll vector< vll >
#define vld vector< ld >
#define vvld vector< vld >
#define pll pair<ll ,ll >
#define vpll vector< pll >
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define endl "\n"
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ff first
#define ss second
#define mk(arr,n,type)  type *arr=new type[n];

 
#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))
 
using namespace std;
 
///////////////////////////////////////////////////////////////////////// Maths //////////////////////////////////////////////////////////////////////////////

//vll sieve;
//void Sieve(int N){  //smallest prime factor
//	const ll maxn = N;
//	sieve.resize(maxn);
//	forn(i,maxn) sieve[i] = i;
//	sieve[1] = -1;
//	sieve[0] = -1;
//	forab(i,2,maxn,1) if(i == sieve[i]) for(ll j = i*i ; j < maxn ; j+=i) if(sieve[j] == j) sieve[j] = i;
//	
////	for(auto i:sieve){
////		cout<<i<<" ";
////	}
//
//}
vll sieve;
vll* Sieve(int N){
	const ll maxn = N;
	sieve.resize(maxn);
	forn(i,maxn) sieve[i] = 1;
	sieve[1] = 0;
	sieve[0] = 0;
	forab(i,2,maxn,1) if(1 == sieve[i]) for(ll j = i*i ; j < maxn ; j+=i) sieve[j] = 0;
	
	vll* primes=new vll();
	primes->pb(2);
	for(int i=3;i<maxn;i+=2)
	if(sieve[i]){
		primes->pb(i);
	}
	return primes;
 
}
 
   
ll extended_GCD(ll a , ll b , ll &x , ll &y){
	if(a == 0){
		x = 0;
		y = 1;
		return b;
	}
	ll x1 , y1;
	ll gcd = extended_GCD(b%a , a , x1 , y1);
	x = y1 - (b/a)*x1; 
	y = x1;
	return gcd;
}
 
ll power(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
ll modinv(ll a , ll mod = MOD){
	ll x , y;
	extended_GCD(a , mod , x , y);
	if(x < 0) x += mod;
	return x;
}
  
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 bool prime(int n){
 	int c=0;
 	for(int i=2;(i*i)<=n;i++)
 	{
	 if(n%i==0)
 	{
	 c++;
	 return false;
}
}
 	if(c==0)
 	return true;
 }
// bool compareInterval(char i1, char i2) 
//{ 
//    return (i1 < i2); 
//}
// int countoperation(int n,m){
// 	vector<int> d<m+1,-1>;
// }

int val[100001];
pair<int,int> st[4*100001];


void solve(){
	int n;
	cin>>n;
	if(n>=30)
	cout<<"Yes\n";
	else
	cout<<"No\n";
	
}
	

int main()
{
	flash
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout); 

//  test
	 solve();
    return 0;
}
