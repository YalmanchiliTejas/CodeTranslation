#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    int cnt = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c; cin >> c;
            cnt += c == '#';
        }
    }

    cout << (cnt == h + w - 1 ? "Possible" : "Impossible") << endl;

    return 0;
}
