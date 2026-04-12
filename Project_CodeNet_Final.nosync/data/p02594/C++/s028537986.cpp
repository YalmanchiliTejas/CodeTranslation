#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ld long double
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))//memset only use to initialize 0 or -1 no other number.
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 1e9
#define INFL 1e18
#define mod 1000000007
//#define mod 998244353
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds; 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> os_pair;

ll power(ll x,ll n){ll res =1;while(n>0){if(n%2==1){res=res*x;}x=x*x;n=n/2;}return res;}
ll powm(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

//cout<< fixed << setprecision(10)


int main(){

    fast;
    int x;
    cin>>x;
    if(x>=30)
    {
    	cout<<"Yes\n";
	}
	else
	{
		cout<<"No";
	}
    

}