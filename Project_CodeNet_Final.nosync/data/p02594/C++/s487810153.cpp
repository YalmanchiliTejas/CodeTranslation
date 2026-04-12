#include <iostream>
#include<map>
#include<vector>
#include<cmath>
#include<cstring>
#include<climits>
#include<queue>
#include<unordered_set>
#include<algorithm>
#include<iomanip>
#include <set>
#define ll long long int
using namespace std;
const ll mod=1e9+7;
double pi=3.1415926535;

ll gcd(ll a,ll b){if(b == 0){return a;} return gcd(b, a % b);}
ll power(ll a,ll n){ll res=1;while(n){if(n%2){res=res*a;}n=n/2;a=a*a;}return res;}
bool checkprime(ll n){for(ll i=2;i*i<=n;i++){if(n%i==0){return false;}}return true;}
ll mpow(ll a,ll n){ll res=1;while(n){if(n%2){res=(res*a)%mod;}a=(a*a)%mod;n=n/2;}return res;}


void solve()
{
	int n;
	cin>>n;
	if(n>=30){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}
int main()
{
	
	ll t=1;
    //cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}


	//for(int i=1;i<=ma;i++){cout<<dp[i]<<" ";if(dp[i]==1){cnt++;}}
	//cout<<endl;