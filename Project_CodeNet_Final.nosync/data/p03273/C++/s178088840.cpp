#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    int h, w;
    cin >> h >> w;
    string a[h];
    for (int i = 0; i < h; i++) cin >> a[i];
    vector<int> w_crush;
    w_crush.push_back(1000);
    for (int j = 0; j < w; j++) {
        bool flag = true;
        for (int i = 0; i < h; i++) {
            if (a[i][j] == '#') flag = false;
        }
        if (flag) w_crush.push_back(j);
    }
    sort(w_crush.begin(), w_crush.end());
    vector<int> h_crush;
    h_crush.push_back(1000);
    for (int i = 0; i < h; i++) {
        bool flag = true;
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') flag = false;
        }
        if (flag) h_crush.push_back(i);
    }
    sort(h_crush.begin(), h_crush.end());
    for (int i = 0; i < h; i++) {
        if (i == *lower_bound(h_crush.begin(), h_crush.end(), i)) continue;
        for (int j = 0; j < w; j++) {
            if (j == *lower_bound(w_crush.begin(), w_crush.end(), j)) continue;
            cout << a[i][j];
        }
        cout << endl;
    }
}