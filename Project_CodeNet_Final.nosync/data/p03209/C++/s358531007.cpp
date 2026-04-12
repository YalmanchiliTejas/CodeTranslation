#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
#include <queue>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define print(x) cout<<(x)<<'\n'
#define print_vec(v) rep(i,v.size()){if(i!=0)cout<<" ";cout<<v[i];}cout<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<'\n'
#define DEBUG_VEC(v) cout<<#v<<":";rep(i,v.size())cout<<" "<<v[i];cout<<'\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007 //10^9+7
#define fi first
#define sc second
using ll=long long;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vstr=vector<string>;

vll total_layer,p_layer;

ll func(ll n, ll x){
    if(n == 0) return x>0;

    if(x <= 1+total_layer[n-1]) return func(n-1,x-1);
    else return p_layer[n-1] + 1 + func(n-1, x-2-total_layer[n-1]);
}

void solve() {
    ll N,X;
    cin >> N >> X;
    ll layer = 1, p = 1;;
    rep(i,N+1){
        total_layer.pb(layer);
        layer = 2*layer+3;
        p_layer.pb(p);
        p = 2*p+1;
    }
    print(func(N,X));
}
 
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
	cout<<fixed<<setprecision(20);
    //int q; cin >> q;
	//while (q--)
		solve();
    return 0;
}