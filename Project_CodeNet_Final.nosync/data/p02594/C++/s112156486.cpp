/*** akshaykumar99 ***/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template<typename T> using id_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update> ;

const long long MOD = 1e9+7;
const long double PI = acos(-1);
const long long N = 2e5+1;
 
typedef long long ll;
typedef long double ld;

void test_case()
{
    ll x;
    cin >> x;
    if( x >= 30)
    	cout << "Yes\n";
   	else
   		cout << "No\n";

}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    ll tc=1;
    // cin>>tc;
    while(tc--)
        test_case();
    return 0;
}