#include <cstdio>
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <queue>

#define maxn 100010
#define inf 1e9

using namespace std;

typedef pair<int, int> point;

#define x first
#define y second

vector<string> list[210][210];

double sq(double a){
    return a*a;
}

int main() {
    // freopen("POLYGON.in", "r", stdin);
    // freopen("POLYGON.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    
    string s[110];
    vector<pair<int,int>> v;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = "#" + s[i];
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '#') {
                v.push_back({i, j});
            }
        }
    }
    
    sort(v.begin(), v.end());
    int x = 0;
    int y = 1;
    for (auto cell : v) {
        if (cell.x == x + 1 && cell.y == y || cell.x == x && cell.y == y+1) {
            x = cell.x;
            y = cell.y;
        } else {
            cout << "Impossible";
            return 0;
        }
    }
    
    if (x != n || y != m) {
        cout << "Impossible";
    } else {
        cout << "Possible";
    }
}