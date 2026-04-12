#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<char>> vvc(h, vector<char> (w));
    vector<bool> row(h, false), col(w, false);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> vvc[i][j];
            if (vvc[i][j] == '#') row[i] = col[j] = true;
        }
    }

    for (int i = 0; i < h; i++) {
        if (!row[i]) continue;
        for (int j = 0; j < w; j++) {
            if (!col[j]) continue;
            cout << vvc[i][j];
        }
        cout << endl;
    }

    return 0;
}
