#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    int h, w;
    cin >> h >> w;
    vector<string> ss(h);
    REP(i,h) cin >> ss[i];
    vector<string> tt(h,string(w,'.'));
    tt[0][0] = '#';
    int y = 0, x = 0;
    while(y != h-1 || x != w-1) {
        if (y < h-1 && ss[y+1][x] == '#') {
            y++;
            tt[y][x] = '#';
        } else if (x < w-1 && ss[y][x+1] == '#') {
            x++;
            tt[y][x] = '#';
        } else break;
    }

    bool ans = (y == h-1 && x == w-1);
    if (ans) {
        REP(i,h) {
            if (ss[i] != tt[i]) ans = false;
        }
    }

    if (ans) OUT("Possible")
    else OUT("Impossible")


    return 0;
}