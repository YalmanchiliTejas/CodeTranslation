#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int n, m;
vector<string> fi;

int main() {
    cin >> n >> m;
    fi.resize(n);
    for (int i = 0; i < n; ++i) cin >> fi[i];
    vector<bool> tate(n, 0), yoko(n, 0);
    for (int i = 0; i < n; ++i) {
        bool tmp = true;
        for (int j = 0; j < m; ++j) if (fi[i][j] == '#') tmp = false;
        if (tmp) tate[i] = true;
    }
    for (int j = 0; j < m; ++j) {
        bool tmp = true;
        for (int i = 0; i < n; ++i) if (fi[i][j] == '#') tmp = false;
        if (tmp) yoko[j] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (tate[i]) continue;
        for (int j = 0; j < m; ++j) {
            if (yoko[j]) continue;
            cout << fi[i][j];
        }
        cout << endl;
    }
}
