#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    int cnt = 0; char x;
    for (int i = 0; i < h * w; i++) {
        cin >> x;
        if (x == '#') cnt++;
    }
    if (cnt == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}