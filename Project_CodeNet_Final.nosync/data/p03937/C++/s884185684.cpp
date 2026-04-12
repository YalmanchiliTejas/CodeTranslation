#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int H,W;
    cin >> H >> W;
    vector<string>A(H);
    int cnt = 0;
    for(int i = 0; i < H; i++) {
        cin >> A[i];
        for(int j = 0; j < W; j++) {
            if(A[i][j] == '#') {
                cnt++;
            }
        }
    }
    if(cnt == H+W-1) {
        cout << "Possible" << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
}
