/*input
10000000000 10 99959
*/
/**
    Author: Kristopher Paul
    Date Created: 08-09-2020
**/
#include<bits/stdc++.h>
#include<stdio.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define int ll
#define pb push_back
#define INF 1e18
#define MOD 1000000007
//#define MOD 998244353
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define umap map
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define all(v) v.begin(),v.end()
#define WL(t) while(t--)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define out(x) cout << #x << " is " << x << endl
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

//Uncomment for File I/O
//ifstream fin("input.in")

//using namespace __gnu_pbds;

//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // set
//typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> pbds; // multiset

int ModExp(int x,int y,int m){
    int res = 1;
    x = x % m;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % m;

        y = y>>1;
        x = (x*x) % m;
    }
    return res;
}

void solve(){
    int n,x,m;
    cin >> n >> x >> m;
    vi vec;
    vec.pb(x);
    umap<int,int> th;
    int ind = 2;
    th[x] = 1;
    int rep = 0;
    while(true){
        int nx = ModExp(vec[ind-2],2,m);
        if(th[nx] != 0){
            rep = th[nx];
            break;
        }
        vec.pb(nx);
        th[nx] = ind;
        ind++;
    }
    rep--;
    if(n <= vec.size()){
        int ans = 0;
        FOR(i,0,n){
            ans += vec[i];
        }
        cout << ans << endl;
        return;
    }
    int sz = vec.size();
    int ans = 0;
    FOR(i,0,sz){
        ans += vec[i];
    }
    n -= sz;
    int bsz = sz-rep;
    int tim = n/bsz;
    n = n%bsz;

    int bs = 0;
    FOR(i,rep,sz){
        bs += vec[i];
    }
    ans += tim*bs;
    FOR(i,rep,rep+n){
        ans += vec[i];
    }
    cout << ans << endl;
}

signed main(){
    FastIO;
    int t = 1;
//    cin >> t;
    WL(t){
        solve();
    }
}
