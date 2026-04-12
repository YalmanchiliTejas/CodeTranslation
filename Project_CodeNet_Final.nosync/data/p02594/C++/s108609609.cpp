/*
(1)for binary shift operator always use 'LL' 1LL<<63

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set_pair tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define Luv(...) [&] (auto &&u, auto &&v) { return __VA_ARGS__; }
  const double  pi=3.1415926535; 
  struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;cin>>n;
	if(n>=30)
		cout<<"Yes";
	else cout<<"No";

	return 0;
} 