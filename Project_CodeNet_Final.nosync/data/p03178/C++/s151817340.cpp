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
    string k;
    cin >> k;
    ll n = k.size();
    reverse(k.begin(),k.end());
    ll d;
    cin >> d;
    vector <vector<ll>> dp(n,vector<ll>(d,0));
    for(int x=0;x<10;x++){
        dp[0][x%d]++; 
    }
    for (int z=1;z<n;z++){
        for (int x=0;x<d;x++){
            for (int y=0;y<10;y++){
                ll temp = (x-y)%d;
                while (temp < 0) temp += d;
                dp[z][x] += dp[z-1][temp];
                dp[z][x] %= mod;
            }
        }
    }
    ll ans = 0;
    ll sum = 0;
    for (int z=1;z<n;z++){
        sum += k[z]-'0';
    }
    for (int z=0;z<=k[0]-'0';z++){
        if ((sum+z)%d == 0) ans++;
    }
    ans %= mod;
    for (int z=1;z<n;z++){
        ll count = k[z]-'0';
        sum -= count;
        for (int y=0;y<count;y++){
            ll temp = (d-(sum%d)-y)%d;
            while (temp < 0) temp += d;
            ans += dp[z-1][temp];
            ans %= mod;
        }
    }
    ans--;
    if (ans < 0) ans += mod;
    cout << (ans)%mod << endl;
}