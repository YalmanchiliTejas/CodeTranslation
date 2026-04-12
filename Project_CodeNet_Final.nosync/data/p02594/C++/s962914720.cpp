#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
typedef long long int ll;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define MOD 1000000007
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);  
//*s.find_by_order(p)   returns the value of pth largest starting from 0 
//s.order_of_key(p)   returns no. of items that are strictly < p 
//string bin = bitset<64>(m).to_string();     convert decimal m to binary
int main()
{
	fast;ll t;t=1;
	while(t--)
	{
		ll n;
		cin>>n;
		if(n>=30){cout<<"Yes\n";}
		else{cout<<"No\n";}
	}
}