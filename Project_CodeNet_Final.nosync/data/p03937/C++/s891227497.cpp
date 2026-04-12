#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x-I .)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

int H, W;
vector<vector<char>> nap(10, vector<char>(10));

bool exist(int i, int j, vector<vector<char>> now){
    if(i == H && j == W){
        bool ok = true;
        REP(i,H)REP(j,W){
            if(nap[i][j] == '#')if(now[i][j] != '#')ok = false;
        }
        return ok;
    }
    bool res = false;
    vector<vector<char>> rgo = now;
    vector<vector<char>> dgo = now;
    rgo[i][j+1] = '#';
    dgo[i+1][j] = '#';
    if(j < W)if(exist(i, j+1, rgo))res = true;
    if(i < H)if(exist(i+1, j, dgo))res = true;
    return res;
}

int main(){
    cin >> H >> W;
    REP(i,H)REP(j,W)cin >> nap[i][j];
    vector<vector<char>> so(10, vector<char>(10));
    so[1][1] = '#';
    cout << (exist(1,1,so) ? "Possible" : "Impossible") << endl;
    return 0;
}