#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e9;
signed main() {
	int H,W;
    cin >> H >> W;
    vector<string>S(H);
    int cnt = 0;
    for(int i = 0; i < H; i++) {
        cin >> S[i];
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') {
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