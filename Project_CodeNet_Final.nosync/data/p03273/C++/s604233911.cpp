#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    vector<vector<char> > a(H, vector<char>(W));

    vector<bool> b(H);
    vector<bool> c(W);

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> a[i][j];
            if(a[i][j] == '#') {
                b[i] = true;
                c[j] = true;
            }
        }
    }

    for(int i = 0; i < H; i++) {
        if(!b[i]) continue;
        for(int j = 0; j < W; j++) {
            if(c[j]) {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
}