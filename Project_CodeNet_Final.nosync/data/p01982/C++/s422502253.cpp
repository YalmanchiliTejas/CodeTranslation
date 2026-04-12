#include <bits/stdc++.h>
using namespace std;

int n, l, r;

int solve(int year, vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (year % v[i] == 0) {
            return i + 1;
        }
    }
    return -v.size();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (1) {
        cin >> n >> l >> r;
        if (!n & !l & !r) break;
        vector<int> furui;
        int t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            furui.push_back(t);
        }
        int ans = 0, res;
        for (int i = l; i <= r; i++) {
            res = solve(i, furui);
            if (res < 0) {
                if ((-res) % 2 == 0) ans++;
            } else {
                if (res % 2 == 1) ans++;
            }
        }
        cout << ans << endl;
    }
}
