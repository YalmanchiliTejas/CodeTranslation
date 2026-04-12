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
    int H, W;
    cin >> H >> W;
    vector<string> ss(H);
    REP(i,H) cin >> ss[i];

    vector<string> s2(H,string(W,'.'));
    s2[0][0] = '#';
    vector<int> dx{0,1};
    vector<int> dy{1,0};
    queue<pii> que;
    que.push({0,0});
    while(!que.empty()) {
        //cerr << que.front().first << " " << que.front().second << endl;
        pii xy = que.front(); que.pop();
        REP(i,2) {
            int nx = xy.first + dx[i];
            int ny = xy.second + dy[i];
            if (nx >= W) continue;
            if (ny >= H) continue;
            if(ss[ny][nx] == '#') {
                que.push({nx,ny});
                s2[ny][nx] = '#';
                break;
            }
        }
    }

    bool ans = true;
    REP(i,H) {
        if (ss[i] != s2[i]) {
            ans = false;
            break;
        }
    }
    
    if (ans) OUT("Possible")
    else OUT("Impossible")

    return 0;
}