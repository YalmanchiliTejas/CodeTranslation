#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 101;
string s[N];
bool vis[N][N];
int H , W;
int main(){
    cin >> H >> W;
    rep(i,0,H) cin >> s[i];
    int x = 0 , y = 0;
    while(1){
        if(s[x][y] != '#') break;
        vis[x][y] = true;
        if(x != H - 1 && s[x + 1][y] == '#') x++;
        else if(y != W - 1 && s[x][y + 1] == '#') y++;
        else break;
    }
    bool ok = true;
    rep(i,0,H) rep(j,0,W) if(s[i][j] == '#' && !vis[i][j]) ok = false;
    if(!vis[0][0] || !vis[H - 1][W - 1]) ok = false;
    cout << (ok ? "Possible" : "Impossible") << endl;
    return 0;
}
