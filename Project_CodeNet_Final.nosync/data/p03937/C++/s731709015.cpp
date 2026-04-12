#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); ++i)
int dx[] = {1, 0};
int dy[] = {0, 1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];
    int cnt = 0;
    rep(i, h) {
        rep(j, w) {
            if (a[i][j] == '#') cnt++;
        }
    }
    bool ans = (cnt == h+w-1);
    cout << (ans ? "Possible" : "Impossible") << endl;
}