#include<bits/stdc++.h>
		#include <ext/pb_ds/assoc_container.hpp>
		#include <ext/pb_ds/tree_policy.hpp>
		using namespace __gnu_pbds;
		using namespace std;
		typedef long long ll;
		typedef unsigned long long int ull;
		// PB-DS
		#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
		#define ff first
		#define ss second
		#define pb push_back
		#define Inf  1000000000000000000
		#define inf -1000000000000000000
		#define mod 1000000007
 
		ll mulmod(ll x,ll y){
			  return (x%mod*y%mod)%mod;
		}
 
		ll addmod(ll x,ll y){
			  return (x%mod+y%mod)%mod;
		}
 
		long long  power(long long  x,long long  y) {
				long long  res = 1;
				x = x%mod;
				while (y > 0)
				{
					if (y & 1)
						res = (res*x)%mod;
					y = y>>1;
					x = (x*x)%mod;
				}
				return res;
		}
	
 
void testcases(int cases){
		int c;
		cin >> c;
		if(c>=30)
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";
}
	
		 
int main()
{
		
	//sieve();
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
		ll t;
		t = 1;
				//cin >> t;
		ll Case =1 ;
		while(t--)
		{
		 testcases(Case++);
		}
}
