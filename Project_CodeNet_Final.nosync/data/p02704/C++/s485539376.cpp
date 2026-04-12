#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define Rep(i,n) for(int i=1;i<=(n);++i)
using LL = long long;
using ULL = unsigned long long;

ULL a[500][503];
int st[2][503];
ULL uv[2][503];
vector<int> p[8];

int main()
{
    int n;
    cin >> n;
    rep(k, 2) rep(i, n) cin >> st[k][i];
    rep(k, 2) rep(i, n) cin >> uv[k][i];
    rep(j, 64) {
        for(auto& _ : p) _.clear();
        rep(k, 2) rep(i, n) {
            p[k<<2 | st[k][i]<<1 | uv[k][i]>>j&1].push_back(i);
        }
        rep(op, 2) {
            int x = op<<1 | op^1, y = x ^ 7;
            if(p[x].size() && p[y].size()) {
                puts("-1");
                return 0;
            }
        }
        rep(k, 2) rep(op, 2) {
            int x = k<<2 | op<<1 | op^1, y = x ^ 5;
            if(p[x].size() == n && p[y].size()) {
                puts("-1");
                return 0;
            }
        }
        bool cross = false;
        ULL c;
        rep(op, 2) {
            int x = op<<1 | op^1, y = x ^ 4;
            if(p[x].size() && p[y].size()) {
                cross = true;
                c = op ^ 1;
            }
        }
        if(cross) {
            if(c) {
                for(int x : p[1]) rep(i, n) a[x][i] |= 1llu << j;
                rep(i, n) for(int x : p[5]) a[i][x] |= 1llu << j;
            }
            else {
                rep(i, n) rep(k, n) a[i][k] |= 1llu << j;
                for(int x : p[2]) rep(i, n) a[x][i] &= ~(1llu << j);
                rep(i, n) for(int x : p[6]) a[i][x] &= ~(1llu << j);
            }
            continue;
        }
        if(p[1].size() && p[2].size()) {
            for(int x : p[1]) rep(i, n) a[x][i] |= 1llu << j;
            for(int x : p[3]) rep(i, n) a[x][i] |= 1llu << j;
        }
        else if(p[5].size() && p[6].size()) {
            rep(i, n) for(int x : p[5]) a[i][x] |= 1llu << j;
            rep(i, n) for(int x : p[7]) a[i][x] |= 1llu << j;
        }
        else if(p[1].size()) {
            for(int x : p[1]) rep(i, n) a[x][i] |= 1llu << j;
            for(int x : p[3]) rep(i, n) a[x][i] |= 1llu << j;
            if(p[1].size() + p[3].size() == n) for(int k = 0; k < p[4].size(); ++k) {
                int y = p[4][k], x = p[3][k % p[3].size()];
                a[x][y] &= ~(1llu << j);
            }
        }
        else if(p[2].size()) {
            if(p[0].size() + p[2].size() == n) for(int k = 0; k < p[7].size(); ++k) {
                int y = p[7][k], x = p[0][k % p[0].size()];
                a[x][y] |= 1llu << j;
            }
            else for(int x : p[3]) rep(i, n) a[x][i] |= 1llu << j;
        }
        else if(p[5].size()) {
            rep(i, n) for(int x : p[5]) a[i][x] |= 1llu << j;
            rep(i, n) for(int x : p[7]) a[i][x] |= 1llu << j;
            if(p[5].size() + p[7].size() == n) for(int k = 0; k < p[0].size(); ++k) {
                int x = p[0][k], y = p[7][k % p[7].size()];
                a[x][y] &= ~(1llu << j);
            }
        }
        else if(p[6].size()) {
            if(p[4].size() + p[6].size() == n) for(int k = 0; k < p[3].size(); ++k) {
                int x = p[3][k], y = p[4][k % p[4].size()];
                a[x][y] |= 1llu << j;
            }
            else rep(i, n) for(int x : p[7]) a[i][x] |= 1llu << j;
        }
        else if(p[3].size() && p[7].size()) {
            for(int x : p[3]) for(int y : p[7]) a[x][y] |= 1llu << j;
        }
        else if(p[3].size()) for(int x : p[3]) a[x][x&1] |= 1llu << j;
        else for(int y : p[7]) a[y&1][y] |= 1llu << j;
    }
    bool flag = true;
    rep(i, n) {
        ULL _;
        if(st[0][i]) {
            _ = 0;
            rep(j, n) _ |= a[i][j];
        }
        else {
            _ = ~0llu;
            rep(j, n) _ &= a[i][j];
        }
        flag = flag && _ == uv[0][i];
        if(st[1][i]) {
            _ = 0;
            rep(j, n) _ |= a[j][i];
        }
        else {
            _ = ~0llu;
            rep(j, n) _ &= a[j][i];
        }
        flag = flag && _ == uv[1][i];
    }
    if(flag) rep(i, n) rep(j, n) printf("%llu%c", a[i][j], " \n"[j==n-1]);
    else puts("-1");
    return 0;
}
