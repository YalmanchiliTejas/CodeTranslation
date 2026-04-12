#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
 
int n;
vector<vector<int> > a;
const int MAX = 15;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
 
bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}
 
void Rotate() {
    int r, c, size, angle;
    cin >> r >> c >> size >> angle;
    --r; --c;
    angle /= 90;
 
    const int cp = size - 1;
 
    for(int t = 0; t < angle; ++t) {
        vector<vector<int> > tmp(a);
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                int tx = -i + cp;
                int ty = j;
                tmp[ty + r][tx + c] = a[i + r][j + c];
            }
        }
        a.swap(tmp);
    }
}
 
void Reversal() {
    int r, c, size;
    cin >> r >> c >> size;
    --r; --c;
 
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            a[i + r][j + c] = !a[i + r][j + c];
		}
	}
}
 
void LeftShift() {
    int r;
    cin >> r;
    --r;
    rotate(a[r].begin(), a[r].begin() + 1, a[r].end());
}
 
void RightShift() {
    int r;
    cin >> r;
    --r;
    rotate(a[r].begin(), a[r].begin() + n - 1, a[r].end());
}
 
void dfs(int y, int x, const int v) {
    if(a[y][x] != v)
        return;
 
    a[y][x] = !a[y][x];
    for(int i = 0; i < 4; ++i) {
        const int nx = x + dx[i];
        const int ny = y + dy[i];
        if(valid(nx, ny)) {
            dfs(ny, nx, v);
        }
    }
}
 
void IslandReversal() {
    int r, c;
    cin >> r >> c;
    --r; --c;
 
    dfs(r, c, a[r][c]);
}
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    int m;
    cin >> n >> m;  
 
    a.resize(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
		}
	}
 
    for(int i = 0; i < m; ++i) {
        int o;
        cin >> o;
 
        switch(o) {
        case 0: Rotate(); break;
        case 1: Reversal(); break;
        case 2: LeftShift(); break;
        case 3: RightShift(); break;
        case 4: IslandReversal(); break;
        }
    }
 
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << a[i][j]  << (j + 1 == n ? "\n" : " ");
		}
	}
 
    return EXIT_SUCCESS;
}