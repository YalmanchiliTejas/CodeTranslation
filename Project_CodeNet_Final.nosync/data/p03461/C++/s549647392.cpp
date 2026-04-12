#include <bits/stdc++.h>

using namespace std;
int m, A, B, d[200][200];
int used[200][200];
vector<pair<int, int> > ed[2000];
void add(int x, int y, int z) {
    ed[x].push_back(make_pair(y, z));
    m++;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> A >> B;
    for (int i = 1; i <= A; i++)
    for (int j = 1; j <= B; j++) cin >> d[i][j];
    for (int i = 1; i < 99; i++) add(i, i + 1, -1);
    for (int i = 101; i < 200; i++) add(i + 1, i, -2);
    int cnt = 200;
    for (int c1 = 0; c1 < 100; c1++)
    for (int c2 = 0; c2 < 100; c2++)
    for (int c3 = 0; c3 <= 100; c3++) {
        if (c1 + c2 + c3 > 100) break;
        bool bd = 0; vector<pair<int, int> > lst;
        for (int i = 1; i <= A; i++) {
            for (int j = 1; j <= B; j++)
            if (i * c1 + j * c2 + c3 < d[i][j]) {
                bd = 1;
                break;
            }
            else
            if (i * c1 + j * c2 + c3 == d[i][j] && used[i][j] == 0) lst.push_back(make_pair(i, j));
            if (bd == 1) break;
        }
        if (bd) continue;
        if (lst.size() != 0) {
            cnt++;
            add(c1 + 1, cnt, c3);
            add(cnt, c2 + 101, 0);
            for (int i = 0; i < lst.size(); i++) used[lst[i].first][lst[i].second] = 1;
        }
    }
    for (int i = 1; i <= A; i++)
    for (int j = 1; j <= B; j++)
    if (used[i][j] == 0) {
        cout << "Impossible\n";
        return 0;
    }
    cout << "Possible\n";
    cout << cnt << " " << m << "\n";
    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j < ed[i].size(); j++) {
            int to = ed[i][j].first;
            int cs = ed[i][j].second;
            cout << i << " " << to << " ";
            if (cs >= 0) cout << cs << "\n";
            else
            if (cs == -1) cout << "X\n";
            else cout << "Y\n";
        }
    }
    cout << "1 101\n";
    return 0;
}
