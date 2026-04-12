#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int H, W;
    cin >> H >> W;
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        cnt += count(s.begin(), s.end(), '#');
    }
    if (cnt == H+W-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}