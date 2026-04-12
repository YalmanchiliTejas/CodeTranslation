#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define Speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define mod 1000000007
#define fr first
#define sc second
#define pb push_back
#define PI acos(-1.0)
#define print(num,ans) cout<<setprecision(num)<<fixed<<ans
#define ordered_set tree<pair<int,int> , null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>


int main()
{
    Speed;
    int x;
    cin>>x;
    if(x == 3 || x == 7 || x == 5)cout<<"YES";
    else cout<<"NO";
    return 0;
}
