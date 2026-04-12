#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,s,e) for (int i=s;i<(e);i++)
#define All(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int MOD = (int)1e9 + 7;
const int INF = 1010101010;

int bd[10][10];


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    while(s != "#"){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;b--;c--;d--;

        memset(bd, -1, sizeof(bd));
        int y = 0, x = 0;
        for(auto &c : s){
            if(c == '/'){
                x = 0;
                y++;
            }else if(c == 'b'){
                bd[y][x] = 1;
                x++;
            }else{
                REP(i, c-'0'){
                    bd[y][x] = 0;
                    x++;
                }
            }
        }
        assert(bd[a][b] == 1);
        bd[a][b] = 0;
        bd[c][d] = 1;
        string ans = "";
        REP(i, y+1){
            int tmp = 0;
            REP(j, x){
                if(bd[i][j] == 1){
                    if(tmp != 0) ans += to_string(tmp);
                    ans += "b";
                    tmp = 0;
                }
                else tmp++;
            }
            if(tmp != 0) ans += to_string(tmp);
            if(i != y) ans += "/";
        }
        cout << ans << endl;

        cin >> s;
    }
    return 0;
}
