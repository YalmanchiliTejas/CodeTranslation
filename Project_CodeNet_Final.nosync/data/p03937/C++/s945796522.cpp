#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define enld endl //* missspell check
const ll INF = 1LL << 60;

const string YES = "Possible";
const string NO = "Impossible";
ll H, W; 
vector<string> S;
vector<vll> checked;
vll dx{0, 1}, dy{1, 0};

void dfs(ll x, ll y){
    if(checked[x][y])
        return;
    checked[x][y] = 1;
    REP(k, 2){
        ll xto = x + dx[k], yto = y + dy[k];
        if( xto < H && yto < W && !checked[xto][yto] && S[x][y] =='#')
            dfs(xto, yto);
    }
    return;

}

int main(){
    cin >> H >> W;
    S.resize(H);
    REP(i, H){
        cin >> S[i];
    }
    checked.resize(H);
    REP(i, H){
        checked[i].resize(W);
        fill(ALL(checked[i]), 0);
    }
    ll cnt = 0;
    REP(i, H){
        REP(j, W){
            if(S[i][j] =='#')
                cnt++;
        }
    }
    dfs(0, 0);
    if(checked[H-1][W-1] &&(cnt == (H+W-1)))
        cout << YES << endl;
    else
        cout<<NO << endl;
    return 0;
}
