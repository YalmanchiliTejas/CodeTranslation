#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

void insertion_sort(pair<int, string> p[], int n) {
    for (int i = 1; i < n; i++) {
        pair<int, string> k = p[i];
        int j = i - 1;
        while (j >= 0 && p[j].first < k.first) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = k;
    }
    return;
}

int main() {
    bool flag = false;
    int n;
    while (cin >> n && n) {
        if (flag) cout << endl;
        flag = true;
        string s;
        int w, l, d;
        pair<int, string> p[n];
        for (int i = 0; i < n; i++) {
            cin >> s >> w >> l >> d;
            p[i] = { 3 * w + d, s };
        }
        insertion_sort(p, n);
        for (int i = 0; i < n; i++) {
            cout << p[i].second << ',' << p[i].first << endl;
        }
    }
}
