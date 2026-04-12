#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
#define trace(x) cerr << #x << " = " << x << endl
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main()
{
   /*
    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("ouput.txt","w",stdout);
    #endif 
   */

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while(t--){
        ll n, sum = 0;
	cin>>n;
	vector<ll> a(n);
	for(auto &it : a){
		cin>>it;
		sum += it;
	}
	ll ans = 0;
	for(int i = 0; i < n-1; i++){
		sum -= a[i];
		ans = (ans%mod + (((sum%mod)*(a[i]%mod))%mod)%mod)%mod;
	}
	cout<<(ll)(ans)<<endl;
    }
    return 0;
} 
