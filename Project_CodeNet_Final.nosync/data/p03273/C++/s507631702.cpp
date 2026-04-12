#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> table(h, vector<char>(w));
    set<int> h_ignore, w_ignore;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> table[i][j];
            if (table[i][j] == '#') {
                h_ignore.insert(i);
                w_ignore.insert(j);
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (!(h_ignore.find(i) != h_ignore.end()))
            continue;
        for (int j = 0; j < w; j++) {
            if ((w_ignore.find(j) != w_ignore.end()))
                cout << table[i][j];
        }
        cout << endl;
    }
}
