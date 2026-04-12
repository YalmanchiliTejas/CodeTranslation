#include<bits/stdc++.h>
#define pi 3.141592653589793238
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        deque<ll> q;
        for(i = 0; i < n; i++){
            ll x;
            cin >> x;
            if(i % 2 == 0){
                q.pb(x);
            }
            else{
                q.push_front(x);
            }
        }
        while(!q.empty()){
            if(n % 2 == 0){
                cout << q.front() << " ";
                q.pop_front();
            }
            else{
                cout << q.back() << " ";
                q.pop_back();
            }
        }
    }
    return 0;
}