#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = s; i < (n); i++)
#define REP(i,n) FOR(i,0,n)
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
    vector<string> s(h);
    REP(i,h) cin >> s[i];

    vector<string> t(h,string(w,'.'));

    int x = 0, y = 0;
    while(true) {
        t[y][x] ='#';
        if (x < w-1 && s[y][x+1] == '#') x++;
        else if (y < h-1 && s[y+1][x] == '#') y++;
        else break;
    }

    bool ans = true;
    REP(i,h) if (s[i] != t[i]) ans = false;
    if (ans) OUT("Possible")
    else OUT("Impossible")

    return 0;
}