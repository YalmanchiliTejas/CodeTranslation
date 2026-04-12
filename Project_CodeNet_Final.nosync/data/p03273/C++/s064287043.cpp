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

void solve() {
    ll H,W;
    cin >> H >> W;
    vll row(H,0),col(W,0);
    vstr a(H);
    rep(i,H){
        cin >> a[i];
        if(a[i].find("#") != string::npos){
            row[i]=1;
        }
        rep(j,W){
            if(a[i][j]=='#'){
                col[j]=1;
            }
        }
    }

    rep(i,H){
        if(row[i]==1){
            rep(j,W){
                if(col[j]==1){
                    cout << a[i][j];
                }
            }
            cout << '\n';
        }
    }
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