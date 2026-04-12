#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/


const int MA = 100;
const int MA2 = MA + 1;
int A, B, D[10][10];
int C[MA2][MA2];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B;
    rep(x, 0, A) rep(y, 0, B) cin >> D[x][y];

    rep(a, 0, A) rep(b, 0, B) {
        int x = a + 1, y = b + 1;
        rep(i, 0, MA2) rep(j, 0, MA2) chmax(C[i][j], D[a][b] - i * x - j * y);
    }

    rep(a, 0, A) rep(b, 0, B) {
        int x = a + 1, y = b + 1;
        int d = inf;
        rep(i, 0, MA2) rep(j, 0, MA2) chmin(d, i * x + j * y + C[i][j]);
        if (d != D[a][b]) {
            printf("Impossible\n");
            //printf("[%d %d]\n", d, D[a][b]);
            return;
        }
    }

    vector<tuple<int, int, int>> edges;
    rep(i, 0, MA) edges.push_back(make_tuple(i, i + 1, -1));
    rep(i, 0, MA) edges.push_back(make_tuple(MA2 + i, MA2 + i + 1, -2));
    rep(i, 0, MA2) rep(j, 0, MA2) edges.push_back(make_tuple(i, MA2 * 2 - 1 - j, C[i][j]));

    printf("Possible\n");
    printf("%d %d\n", MA2 * 2, edges.size());
    fore(t, edges) {
        int a, b, c;
        tie(a, b, c) = t;
        a++; b++;
        if (c == -1) printf("%d %d X\n", a, b);
        else if (c == -2) printf("%d %d Y\n", a, b);
        else printf("%d %d %d\n", a, b, c);
    }
    printf("1 %d\n", MA2 * 2);
}
