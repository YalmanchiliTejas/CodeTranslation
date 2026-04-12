#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define MOD 1000000007
ll power(ll a, ll b) { //a^b
	ll res = 1;
	while (b > 0) {
		if (b & 1) {res = (res * a); b--;}
		a = (a * a);
		b >>= 1;
	}
	return res;
}
ll n;
ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}



int main() {
	ll n;
	cin>>n;
	vector <ll> a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i];
	vector < vector <ll> > dp(n,vector <ll> (n,0));
	for(ll i=n-1;i>=0;i--){
		for(ll j=i;j<n;j++){
			if(i==j)
				dp[i][j]=a[i];
			else{
				dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
			}
		}
	}
	cout<<dp[0][n-1]<<"\n";
}
