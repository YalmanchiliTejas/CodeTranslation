#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i, s, n) for(int i = s; i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
typedef long long ll;
const int MOD = 1000000007;
using namespace std;

int main(){
    int h, w; cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<bool> vert(h, false), trans(w, false); //黒のある行、列
    REP(i, h) REP(j, w){
        cin >> a[i][j];
        if(a[i][j] == '#'){
            vert[i] = true; trans[j] = true;
        }
    }
    REP(i, h){
        REP(j, w){
            if(vert[i] && trans[j]) cout << a[i][j];
        }
        if(vert[i]) cout << "\n";
    }
    return 0;
}
