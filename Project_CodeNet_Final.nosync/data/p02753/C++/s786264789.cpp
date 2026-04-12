/*
    Author - Param Kothari
    Ah shit, here we go again
*/
 
/* Ordered Set Implementaton:

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
*/

#include <bits/stdc++.h>
 
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair 
 
typedef long long ll;
typedef long double ld;

void solve(){
    string s;
    cin >> s;
    if(s == "AAA" || s == "BBB"){
        cout << "No\n";
    }
    else cout << "Yes\n";
    return;
}
 
int main(){
    IOS;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
