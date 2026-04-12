#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int r,g,b;
    cin >> r >> g >> b;
    if((10 * g + b) % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}