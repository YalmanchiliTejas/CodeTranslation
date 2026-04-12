#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <tuple>
#include <sstream>
#include <iomanip>
#include <map>
#include <unordered_map>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

using namespace std;
typedef long long ll;

int main(int argc, const char * argv[]) {
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w, ' '));
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            cin >> a[y][x];
        }
    }
    
    vector<bool> vecIsAllWhite(w, true);
    for (int x = 0; x < w; ++x)
    {
        for (int y = 0; y < h; ++y)
        {
            if (a[y][x] == '#')
            {
                vecIsAllWhite[x] = false;
                break;
            }
        }
    }
    
    for (int y = 0; y < h; ++y)
    {
        bool isAllWhite  = true;
        for (int x = 0; x < w; ++x)
        {
            if (a[y][x] == '#') isAllWhite = false;
        }
        if (isAllWhite) continue;
        
        for (int x = 0; x < w; ++x)
        {
            if (vecIsAllWhite[x])
            {
                continue;
            }
            else
            {
                printf("%c", a[y][x]);
            }
        }
        printf("%c", '\n');
    }
    
    return 0;
}