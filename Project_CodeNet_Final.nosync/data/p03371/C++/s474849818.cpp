#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
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
using pi=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vstr=vector<string>;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
void Yes(bool c) { if (c)print("Yes"); else print("No"); };
void YES(bool c) { if (c)print("YES"); else print("NO"); };

void solve() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = min(A+B,2*C)*min(X,Y) + min(A,2*C)*max(0,X-Y) + min(B,2*C)*max(0,Y-X);
    print(ans);
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