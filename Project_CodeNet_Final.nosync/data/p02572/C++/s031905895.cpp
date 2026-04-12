#include <bits/stdc++.h>
// For policy based data structure
/*#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> */
using namespace std;
/*using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set;*/
 
#define MD 1000000007
#define X first
#define Y second
#define pb push_back
#define debug(val, ch) cout <<val <<ch
 
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;
typedef pair<bool, int> pbi;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
/*********************************************************************/
void test(int r)
{
	ll n;
	cin>>n;
	ll a[n],b[n],i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	b[n-1]=a[n-1];
	for(i=n-2;i>=0;i--)
	{
		b[i]=(b[i+1]+a[i])%MD;
	}
	ll ans=0;
	for(i=0;i<n-1;i++)
	{
		ans=(ans+a[i]*b[i+1])%MD;
	}
	cout<<ans;
	

}
/***********************************************************************/
int main()
{
	fast();
    int t=1,r;
    // cin>>t;
    for(r=1;r<=t;r++)
        test(r);
    return 0;
}