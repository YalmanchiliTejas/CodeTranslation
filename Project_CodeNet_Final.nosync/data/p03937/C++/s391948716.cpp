#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
	cin >> H >> W;
    int cnt = 0;
    for(int i = 0; i < H; i++){
    	for(int j = 0; j < W; j++){
    		char A; cin >> A;
    		if(A == '#') cnt++;
    	}
    }
    if(cnt == H+W-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}