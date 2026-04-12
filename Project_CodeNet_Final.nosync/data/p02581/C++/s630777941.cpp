#include <bits/stdc++.h>
using namespace std;
struct Update {
    int a1;
    int a2;
    int val;
    Update(int a, int b, int c) : a1(a), a2(b), val(c) {};
};
int main() {
    int n, ttt;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < 3 * n; i++) {
        cin >> ttt;
        a.push_back(ttt - 1);
    }
    int res = 0;
    if (n == 1) {
        res = (a[0] == a[1]) && (a[1] == a[2]);
        cout << res;
        return 0;
    }
    vector<vector<int>> point(n, vector<int>(n, -12800));
    vector<Update> up;
    vector<int> maxWhenX(n, -64800);
    //Initialize
    point[a[0]][a[1]] = 0;
    point[a[1]][a[0]] = 0;
    maxWhenX[a[0]] = 0;
    maxWhenX[a[1]] = 0;
    vector<int> te;
    int m = 0;
    for (int i = 1; i < n; i++) {
        te.clear();
        te.push_back(a[3 * i - 1]);
        te.push_back(a[3 * i]);
        te.push_back(a[3 * i + 1]);
        if (te[0] == te[1] && te[1] == te[2]) {
            res++;
            continue;
        }
        up.clear();
        up.push_back(Update(te[0], te[1], m));
        up.push_back(Update(te[0], te[2], m));
        up.push_back(Update(te[1], te[2], m));
        up.push_back(Update(te[0], te[1], point[te[2]][te[2]] + 1));
        up.push_back(Update(te[2], te[1], point[te[0]][te[0]] + 1));
        up.push_back(Update(te[0], te[2], point[te[1]][te[1]] + 1));
        for (int j = 0; j < n; j++) {
            up.push_back(Update(te[0], j, maxWhenX[j]));
            up.push_back(Update(te[1], j, maxWhenX[j]));
            up.push_back(Update(te[2], j, maxWhenX[j]));
            if (te[0] == te[1]) up.push_back(Update(te[2], j, point[te[0]][j] + 1));
            else if (te[2] == te[1]) up.push_back(Update(te[0], j, point[te[1]][j] + 1));
            else if (te[0] == te[2]) up.push_back(Update(te[1], j, point[te[2]][j] + 1));
        }
        for (auto u : up) {
            point[u.a1][u.a2] = point[u.a2][u.a1] = max(point[u.a1][u.a2], u.val);
            m = max(u.val, m);
            maxWhenX[u.a1] = max(maxWhenX[u.a1], u.val);
            maxWhenX[u.a2] = max(maxWhenX[u.a2], u.val);
            //cout << u.a1 << " " << u.a2 << " " << u.val << endl;
        }
    }
    res = res + max(m, point[a.back()][a.back()] + 1);
    cout << res << endl;
    return 0;
}