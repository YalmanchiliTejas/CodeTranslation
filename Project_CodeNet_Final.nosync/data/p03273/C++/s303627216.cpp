#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    vector<int> ign, ignr;
    for (int i = 0; i < h; i++) {
        bool f = false;
        for (int j = 0; j < w; j++) {
            f += s[i][j] == '#';
        }
        if (f) continue;
        ignr.push_back(i);
    }
    for (int j = 0; j < w; j++) {
        bool f = false;
        for (int i = 0; i < h; i++) {
            f += s[i][j] == '#';
        }
        if (f) continue;
        ign.push_back(j);
    }

    int idxr = 0;
    for (int i = 0; i < h; i++) {
        int idx = 0;
        if (ignr.size() && ignr[idxr] == i) {
            idxr++;
            continue;
        }
        for (int j = 0; j < w; j++) {
            if (ign.size() && ign[idx] == j) {
                idx++;
                continue;
            }
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}
