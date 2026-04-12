#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF (ll)1<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define uni(q) unique(all(q)),q.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;

ll h,w;

bool in(ll y, ll x){
    return 0 <= y && y < h && 0 <= x && x < w;
}

int main(){
    ll dy[4] = {-1, 0, 1, 0};
    ll dx[4] = {0, -1, 0, 1};
    cin >> h >> w;
    char s[h][w];
    vpl kuro;
    rep(i,h){
        rep(j,w){
            cin >> s[i][j];
            if(s[i][j] == '#'){
                if(!((i==0&&j==0) || (i==h-1&&j==w-1))) kuro.emplace_back(i,j);
            }
        }
    }
    bool flag = true;
    for(auto i : kuro){
        ll y = i.first;
        ll x = i.second;
        ll cnt = 0;
        rep(j,2){
            if(in(y+dy[j], x+dx[j])){
                if(s[y+dy[j]][x+dx[j]]=='#') cnt++;
            } 
        }
        if(cnt == 0 || cnt == 2){
            flag = false;
        }
        cnt = 0;
        REP(j,2,4){
            if(in(y+dy[j], x+dx[j])){
                if(s[y+dy[j]][x+dx[j]]=='#') cnt++;
            } 
        }
        if(cnt == 0 || cnt == 2){
            flag = false;
        }
    }
    if(s[0][1] == '#' && s[1][0] == '#') flag = false;
    if(s[h-2][w-1] == '#' && s[h-1][w-2] == '#') flag = false;
    if(flag && !kuro.empty()) puts("Possible");
    else puts("Impossible");
}
