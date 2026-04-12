#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long,long long> ii; 	
typedef complex<long double> com;

const ll mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n;
    cin >> n;
    vector <ll> arr(n);
    for (int z=0;z<n;z++){
        cin >> arr[z];
    }
    vector <vector<ii>> dp(n,vector<ii>(n,{0,LLONG_MAX}));
    for (int z=0;z<n;z++){
        dp[z][z].first = arr[z];
        dp[z][z].second = 0;
    }
    for (int x=1;x<n;x++){
        for (int z=0;x+z<n;z++){
            ll a,b;
            a = dp[z][z+x-1].second+arr[z+x];
            b = dp[z][z+x-1].first;
            if (a-b > dp[z][z+x].first-dp[z][z+x].second){
                dp[z][z+x].first = a;
                dp[z][z+x].second = b;
            }
            a = dp[z+1][z+x].second+arr[z];
            b = dp[z+1][z+x].first;
            if (a-b > dp[z][z+x].first-dp[z][z+x].second){
                dp[z][z+x].first = a;
                dp[z][z+x].second = b;
            }

        }
    }
    cout << dp[0][n-1].first-dp[0][n-1].second << endl;
}