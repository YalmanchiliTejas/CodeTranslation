// Best practice

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <functional> // for less 

#define int         long long
#define pb          emplace_back
#define pf          emplace_front
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define x           first
#define y           second
#define endl        '\n'
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using namespace __gnu_pbds; 
 
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

#define fbo find_by_order
#define ook order_of_key

signed main() {
   tezz
   
    int n,m;
    cin >> n >> m;
    if(n==m)cout << "Yes" << endl;
    else cout << "No" << endl;
  
   return 0;
}