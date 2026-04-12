#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi M_PI
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main() {
    int w, h;
    cin >> w >> h;
    vector<string> s(w+1);
    REP(i,w) cin >> s[i];
    REP(i,w) s[i].push_back('.');

    int x = 0;
    REP(i,w) REP(j,h) x += (s[i][j] == '#');

    int i = 0, j = 0, y = 1;
    while (i < w-1 || j < h-1){
        y++;
        if (s[i+1][j] == '#'){
            i++;
            continue;
        }
        if (s[i][j+1] == '#'){
            j++;
            continue;
        }
        cout << "Impossible" << endl;
        return 0;
    }

    if (x == y) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}