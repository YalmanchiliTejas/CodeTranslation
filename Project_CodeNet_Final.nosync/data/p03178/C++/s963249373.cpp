#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define F first
#define S second
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define pdd pair<ld, ld>
#define pq priority_queue
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define uid uniform_int_distribution
#define FILE ifstream in("input.txt");ofstream out("output.txt");
#define fast cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);cout.sync_with_stdio(0);
using namespace std;
typedef string str;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

str t;
ll a, d, mod = 1e9+7, dp[10001][2][100];

int main() {
    fast;
    for(int q=0; q<10001; q++) for(int w=0; w<2; w++) for(int e=0; e<100; e++) dp[q][w][e] = 0;
    cin>>t>>d;
    a = t.size();
    vec<int> m(a);
    for(int q=0; q<a; q++) m[q] = t[q]-'0';
    for(int w=0; w<=m[0]; w++){
        if(w<m[0]){
            dp[0][0][w%d] += 1;
        }
        else{
            dp[0][1][w%d] += 1;
        }
    }
    for(int q=1; q<a; q++){
        for(int ost=0; ost<d; ost++) {
            for (int w = 0; w < 10; w++) {
                int p = (ost-w+d*100)%d;
                dp[q][0][ost] += dp[q-1][0][p];
                if(w<m[q]){
                    dp[q][0][ost] += dp[q-1][1][p];
                }
                else if(w==m[q]){
                    dp[q][1][ost] += dp[q-1][1][p];
                }
                else{
                    ;
                }
            }
            dp[q][0][ost] %= mod;
            dp[q][1][ost] %= mod;
        }
    }
    ll o = dp[a-1][0][0] + dp[a-1][1][0];
    cout<<(o-1+mod)%mod;
}