#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define lli int
#define ulli unsigned long long int
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define loopl(i,a,b) for(lli i=a;i<b;i++) 
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
//#define mod 1000000007
#define mod2 1000000006
#define inf 1000000000000000000
#define lld long double
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<lli>
#define vii vector<int>
#define is indexed_set
#define eps 0.000001
#define endl '\n'
#define mo 998244353
#define pi 3.141592653589793
#define fi first
#define se second
using namespace std ;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
lli m=1000000007;
lli mm(lli a, lli b,  lli mod) 
{ 
    long long res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) 
    { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
} 

void solve()
{
	lli n;
	cin>>n;
	lli a[n];
	loop(i,0,n)cin>>a[i];
	lli pre[n];
	pre[n-1]=a[n-1];
	for(lli i=n-2;i>=0;i--){
		pre[i]=pre[i+1]+a[i];
		pre[i]=pre[i]%m;
	}
	lli ani=0;
	for(lli i=0;i<n-1;i++){
		ani+=mm((pre[i+1]%m),(a[i]%m),m);
		ani=ani%m;
	}
	cout<<ani;
}
 
int main()
{
/////////////////////////////////////
    fastio;
    
/////////////////////////////////////  
    lli t,m;
    //cin>>t;
    t=1;
    while(t--)
    {
    	solve();  
    	m++;  
    	cout<<endl;
    }
}