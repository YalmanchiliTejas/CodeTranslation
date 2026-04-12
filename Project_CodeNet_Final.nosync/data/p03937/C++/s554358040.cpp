#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


int main(){

    int H, W;
    cin >> H >> W;
    int cnt = 0;
    for(int y = 0; y < H; y++){
        for(int x = 0; x < W; x++){
            char c;
            cin >> c;
            if(c == '#')cnt++;
        }
    }
    if(cnt == H + W - 1)cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}