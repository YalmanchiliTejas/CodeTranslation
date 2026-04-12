#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <numeric>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF 999999999
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
int h, w;
string a[10];
bool ans;
/**********************************************/

void dfs(int x, int y){
    a[y][x] = '.';
    if(x == w-1 && y == h-1){
        ans = true;
        REP(i, h){
            REP(j, w){
    //            cout << a[i][j];
                if(a[i][j] == '#') ans = false; 
            }
      //      cout << endl;
        }
    }
    if(a[y+1][x] == '#'){ 
        dfs(x, y+1);
        a[y+1][x] = '#';
    }
    else if(a[y][x+1] == '#'){ 
        dfs(x+1, y);
        a[y][x+1] = '#';
    }
}

int main(){
    cin >> h >> w;
    REP(i, h){
        cin >> a[i];
    }

    dfs(0, 0);
    if(ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}

