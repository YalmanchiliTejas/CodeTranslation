#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

int ans = 0;
int h, w;
vector<string> mp;
vector<string> flag1, flag2;

void dfs1(int x, int y) {
    if(x == 0 && y == 0 && mp[y][x] == '#') {
        ans++;
        flag1[y][x] = '#';
        return;
    }

    if(mp[y][x] == '.') {
        return;
    }
    if(mp[y][x] == '#') {
        flag1[y][x] = '#';
    }
    if(x-1 >= 0) dfs1(x-1, y);
    if(y-1 >= 0) dfs1(x, y-1);
    /*
    if(y-1 > -1) {
        if(mp[y-1][x] == '#') {
            ans = 2;
        }
    }
    if(x-1 > -1) {
        if(mp[y][x-1] == '#') {
            ans = 2;
        }
    }
    */
}


void dfs2(int x, int y) {
    if(x == w-1 && y == h-1 && mp[y][x] == '#') {
        ans++;
        flag2[y][x] = '#';
        return;
    }

    if(mp[y][x] == '.') {
        return;
    }
    if(mp[y][x] == '#') {
        flag2[y][x] = '#';
    }
    if(x+1 < w) dfs2(x+1, y);
    if(y+1 < h) dfs2(x, y+1);
}

int main() {
    cin >> h >> w;
    //vector<string> mp(h);
    string t = "";
    rep(i, 0, w) {
        t += '.';
    }
    rep(i, 0, h) {
        string s;
        cin >> s;
        mp.push_back(s);
        flag1.push_back(t);
        flag2.push_back(t);
    }
    dfs1(w-1, h-1);
    dfs2(0, 0);
    rep(i, 0, h) {
        rep(j, 0, w) {
            //cout << flag[i][j];
            if(flag1[i][j] != flag2[i][j]) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        //cout << endl;
    }
    if(ans == 2) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
    return 0;
}