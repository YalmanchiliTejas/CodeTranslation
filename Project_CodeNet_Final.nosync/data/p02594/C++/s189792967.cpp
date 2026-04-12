#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
#define ll long long int
#define ld long double
#define pb push_back
#define pll pair<ll,ll>
#define pint pair<int,int>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define mod 1000000007
#define MAX 500010
#define endl '\n'
#define mp make_pair
#define INF INT_MAX
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ff first
#define ss second
#define ps(x,y) fixed<<setprecision(y)<<x
#define setbits(x) __builtin_popcountll(x)            //counts no of ones in binary representation
#define w(t)     int t; cin>>t; while(t--)
#define pi 3.141592653589793238
#define sortt(v)  sort(v.begin(),v.end())
#define lb(v,x) std::lower_bound(v.begin(),v.end(),x)
#define ub(v,x) std::upper_bound(v.begin(),v.end(),x)

using namespace std;

bool isprime(ll n){			//to check whteher no is prime or not
	if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

int main(){
	fast;
	ll x;
	cin>>x;
	if(x>=30){
		cout<<"Yes";
	}
	else	cout<<"No";
	//cout<<"Case #"<<x<<": "<<y<<endl;
}

/*for(int i=2;i<=n;i++){
			if(v[i].size()==0)	break;
			for(int j=0;j<v[i].size();j++){
				cout<<v[i-1][0]<<' '<<v[i][j]<<endl;
			}
		}*/