#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using u128 = __uint128_t;

#define int long long
#define index_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define atIndex find_by_order
#define indexOf order_of_key
#define MOD 1000000007
#define MAX 200005

int dp[MAX];

void solve() {
    int h , w;
    cin>>h>>w;
    char x[101][101];
    for(int i = 0 ; i< h ; i++){
        cin>>x[i];
    }
    // by row....
    vector<int> row;
    for(int i = 0 ; i< h ; i++){
        bool there = false;
        for(int j = 0 ; j < w ; j++){
            if(x[i][j] == '#'){
                there = true;
                break;
            }
        }
        if(there){
            row.push_back(i);
        }
    }
    vector<int> column;
    for(int j = 0 ; j < w ; j++){
        bool there = false;
        for(int i = 0 ; i < h ; i++){
            if(x[i][j] == '#'){
                there = true;
                break;
            }
        }
        if(there){
            column.push_back(j);
        }
    }
    for(auto i : row){
        for(auto j : column){
            cout<<x[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}