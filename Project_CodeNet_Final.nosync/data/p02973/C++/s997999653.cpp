/*author: hyperion_1724
  date: 
*/

//Required Libraries

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

//Required namespaces

using namespace std;
using namespace __gnu_pbds;

//Required defines

#define READ(X) cin>>X;
#define READV(X) long long X; cin>>X;
#define READAR(A,N) long long A[N]; for(int i=0;i<N;i++) {cin>>A[i];}
#define rz(A,N) A.resize(N);
#define sz(X) (long long)(X.size())
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define endl '\n'
#define trav(x,A) for(auto &x:A)
#define veci vector<int>
#define vecl vector<long long>
#define FORI(a,b,c) for(int a=b;a<c;a++)
#define FORD(a,b,c) for(int a=b;a>c;a--)

//Required typedefs

typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long,long> pll;

//Required Constants

const long long inf=(long long)1e18;
const long long MOD=(long long)(1e9+7);
const long long INIT=(long long)(1e6+1);

//Required Functions

ll power(ll x,ll y) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2) % MOD; 
    p = (p * p) % MOD; 
  
    return (y%2 == 0)? p : (x * p) % MOD; 
}
ll modInverse(ll a) 
{ 
   return power(a,MOD-2); 
   
}

//Work

using namespace std; 
  
ll calc(ll arr[], ll N) 
{ 
    multiset<ll> last; 
    FORI(i,0,N) 
    { 
        auto it = last.lower_bound(arr[i]); 
        if (it == last.begin()) 
            last.insert(arr[i]); 
        else 
        { 
            it--; 
            last.erase(it);
            last.insert(arr[i]);
        } 
    } 
    return last.size();
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	READV(N);
	READAR(A,N);
	ll ans=calc(A,N);
	cout<<ans<<endl;

	return 0;
}