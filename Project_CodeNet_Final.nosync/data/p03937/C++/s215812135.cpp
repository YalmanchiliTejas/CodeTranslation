#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for ( int h = 0; h < H; h++ ) {
        cin >> A[h];
    }
    for ( int h = 1; h < H; h++ ) {
        for ( int w = 1; w < W; w++ ) {
            if ( A[h][w] == '#' ) {
                if ( A[h-1][w] == '#' && A[h][w-1] == '#' ) return false;
            }
        }
    }
    for ( int h = 0; h < H-1; h++ ) {
        for ( int w = 0; w < W-1; w++ ) {
            if ( A[h][w] == '#' ) {
                if ( A[h+1][w] == '#' && A[h][w+1] == '#' ) return false;
            }
        }
    }
    return true;
}

int main() {
    string ans = solve() ? "Possible" : "Impossible";
    cout << ans << "\n";
    return 0;
}