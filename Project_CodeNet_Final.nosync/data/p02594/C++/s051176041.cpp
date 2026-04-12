
// Problem : A - Air Conditioner
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// Delete the dynamically allocated memory

#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define pb              push_back
#define pr              pair<long long,long long>
#define mp(a,b)         make_pair(a,b)
#define vr              vector<long long>
#define mod1            1000000007
#define mod2            998244353
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define fill(a,b)       memset(a, b, sizeof(a))
#define mk(arr,n,type)  type *arr=new type[n];
#define ll              long long
#define ld	            long double
#define w(x)            int x; cin>>x; while(x--)
ll power(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base);
       base=(base*base);
       exp/=2;
    }
    return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll x;
	cin>>x;
	if(x>=30){
		cout<<"Yes"<<"\n";
	}else{
		cout<<"No"<<"\n";
	}
	return 0;
	}