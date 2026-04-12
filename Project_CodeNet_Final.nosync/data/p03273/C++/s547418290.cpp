#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<list>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> v(h);
    for (int i = 0; i < h; i++) {
        string vi;
        cin >> vi;
        v[i] = vi;
    }

    vector<bool> row(h, false);
    vector<bool> col(w, false);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (v[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (row[i] == false) {
            continue;
        }
        for (int j = 0; j < w; j++) {
            if (col[j] == false) {
                continue;
            }
            cout << v[i][j];
        }
        cout << endl;
    }


    return 0;
}
