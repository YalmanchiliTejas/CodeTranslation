#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;

int H, W;
vector<string> grid;

int main(void){
    
    scanf("%d %d", &H, &W);
    int cnt = 0;
    for(int i = 0; i < H; ++i){
        string s, c(W, '.'); cin >> s;
        if(s != c) grid.push_back(s);
        else ++cnt;
    }
    H -= cnt;
    
    string c(H, '.');
    map<int, int> mp;
    for(int i = 0; i < W; ++i){
        string d;
        for(int j = 0; j < H; ++j) d.push_back(grid[j][i]);
        if(d == c) ++mp[i];
    }
    
    for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j) if(mp.find(j) == mp.end()) printf("%c", grid[i][j]);
        printf("\n");
    }
    
    return 0;
}