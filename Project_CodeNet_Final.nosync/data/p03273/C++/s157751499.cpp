#include<iostream>
using namespace std;

int main() {
    int h, w;
    char a[110][110];
    int comp_h[110] = {};
    int comp_w[110] = {};

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> a[i][j];
    }

    int ii = 0;
    for (int i = 0; i < h; i++) {
        bool comp_i = true;
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') comp_i = false;
        }
        if (!comp_i) {
            comp_h[ii] = i;
            ii++;
        }
    }

    int jj = 0;
    for (int j = 0; j < w; j++) {
        bool comp_j = true;
        for (int i = 0; i < h; i++) {
            if (a[i][j] == '#') comp_j = false;
        }
        if (!comp_j) {
            comp_w[jj] = j;
            jj++;
        }
    }

    for(int i = 0; i < ii; i++) {
        for (int j = 0; j < jj; j++) {
            cout << a[comp_h[i]][comp_w[j]];
        }
        cout << endl;
    }

}