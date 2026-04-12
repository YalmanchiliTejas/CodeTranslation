#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
#include "atcoder/segtree"

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;
using namespace atcoder;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;
ll op(ll a, ll b) {
    return max(a, b);
}
ll e() {
    return -1;
}

int v;
bool f(ll x){
    return v > x;
}

int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    segtree<ll, op, e> seg(a);
    while(q--){
        int t; cin >> t;
        if(t==1)
        {
            int X,V; cin >> X >> V;
            X--;
            seg.set(X,V);
        }
        else if(t == 2)
        {
            int l, r; cin >> l >> r;
            l--;
            cout << seg.prod(l,r) << endl;
        }
        else
        {
            ll X; cin >> X >> v;
            X--;
            cout << seg.max_right<f>(X) + 1<< endl;
        }
    }

}