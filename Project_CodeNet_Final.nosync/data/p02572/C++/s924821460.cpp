/*
Author : Aditya Gupta
Team : TechTurtle
Date : 29-08-2020
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
#define fst first
#define scd second
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
vll* Sieve(int N) {
	const ll maxn = N;
	sieve.resize(maxn);
	forn(i,maxn) sieve[i] = 1;
	sieve[1] = 0;
	sieve[0] = 0;
	forab(i,2,maxn,1) if(1 == sieve[i]) for(ll j = i*i ; j < maxn ; j+=i) sieve[j] = 0;

	vll* primes=new vll();
	primes->pb(2);
	for(int i=3; i<maxn; i+=2)
		if(sieve[i]) {
			primes->pb(i);
		}
	return primes;

}


ll extended_GCD(ll a , ll b , ll &x , ll &y) {
	if(a == 0) {
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

ll ncr(ll n,ll k) {
	ll r=1;
	if(k>n-k)
		k=n-k;
	for(ll i=0; i<k; i++) {
		r*=(n-i);
		r/=(i+1);
	}
	return r;
}


ll power(ll a, ll b,ll m = MOD) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a)%m;
		a = (a * a)%m;
		b >>= 1;
	}
	
	return res;
}

ll modinv(ll a , ll mod = MOD) {
	ll x , y;
	extended_GCD(a , mod , x , y);
	if(x < 0) x += mod;
	return x;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool prime(int n) {
	int c=0;
	for(int i=2; (i*i)<=n; i++) {
		if(n%i==0) {
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
int lcs(string X, string Y, int m, int n) 
{ 
    // Create a table to store lengths of longest 
    // common suffixes of substrings.   Note that 
    // LCSuff[i][j] contains length of longest 
    // common suffix of X[0..i-1] and Y[0..j-1].  
  
    int LCSuff[m+1][n+1]; 
    int result = 0;  // To store length of the  
                     // longest common substring 
  
    /* Following steps build LCSuff[m+1][n+1] in 
        bottom up fashion. */
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
  
            // The first row and first column  
            // entries have no logical meaning,  
            // they are used only for simplicity  
            // of program 
            if (i == 0 || j == 0) 
                LCSuff[i][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
            { 
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
                result = max(result, LCSuff[i][j]); 
            } 
            else LCSuff[i][j] = 0; 
        } 
    } 
    return result; 
} 

void solve() {

ll n;
cin>>n;
ll a[n],b[n];
forn(i,n){

cin>>a[i];
if(i!=0)
b[i]=a[i]+b[i-1];
else
b[i]=a[i];
}

ll s=0;
forn(i,n-1){
	s+=a[i]*(b[n-1]%MOD-b[i]%MOD+MOD);
	s=s%MOD;
}
cout<<s<<"\n";

}

int main() {
	flash
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

//	test
	solve();
	return 0;
}