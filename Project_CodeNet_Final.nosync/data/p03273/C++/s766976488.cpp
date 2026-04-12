#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h,"");

    for(int i =0; i < h; i++)
        cin >> grid[i];
    unordered_set<int> skip_row;
    unordered_set<int> skip_col;
    for(int i = 0; i < h; i++) {
        int cnt = 0;
        for(int j = 0; j < w; j++) {
            cnt += (grid[i][j] == '.') ? 1 : 0;
        }
        if (cnt == w)
            skip_row.insert(i);
    }
    for(int j =0; j < w; j++) {
        int cnt = 0;
        for(int i = 0; i < h; i++) {
            cnt += (grid[i][j] == '.') ? 1 : 0;
        }
        if (cnt == h)
            skip_col.insert(j);
    }
    for(int i = 0; i < h; i++) {
        if (skip_row.count(i) == 0) {
            for(int j = 0; j < w; j++) {
                if (skip_col.count(j) == 0)
                    cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

