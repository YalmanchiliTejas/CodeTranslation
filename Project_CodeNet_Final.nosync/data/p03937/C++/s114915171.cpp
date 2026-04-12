#include<bits/stdc++.h>
using namespace std;

int main(){

    int cnt = 0;
    int h, w; cin >> h >> w;
    for(int i = 0; i < h * w; i++){
        char c; cin >> c;
        cnt += (c == '#');
    }

    cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;
    return 0;
}