#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int h,w;
    cin >> h >> w;
    int cnt = 0;
    char a;
    REP(i,h){
        REP(j,w){
            cin >> a;
            if(a == '#') cnt++;
        }
    }
    if(cnt == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}