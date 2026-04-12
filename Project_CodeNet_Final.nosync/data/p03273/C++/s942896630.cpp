#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(perm),end(perm)
#define showall(obj) for(auto x:obj)cout<<x<<endl;
typedef long long ll;
typedef pair<int,int> ip;
typedef pair<ll,ll> lp;
typedef vector<int> vint;
typedef vector<ll> vll;
const int inf = 100100100;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int main(){
    int h,w;cin>>h>>w;
    vector<vector<char>> g(h,vector<char>(w));
    rep(i,h)rep(j,w)cin>>g[i][j];
    rep(i,h){
        bool ch = true;
        rep(j,w)if(g[i][j] == '#')ch = false;
        if(ch){
            rep(j,w)g[i][j] = '1';
        }
    }
    rep(j,w){
        bool ch = true;
        rep(i,h)if(g[i][j] == '#')ch = false;
        if(ch){
            rep(i,h)g[i][j] = '1';
        }
    }
    rep(i,h){
        bool p = false;
        rep(j,w)if(g[i][j] != '1'){p = true;cout<<g[i][j];}
        if(p)cout<<endl;
    }
}
