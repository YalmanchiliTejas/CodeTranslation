#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

int main() {
    int n;
    while(cin >> n, n) {
        // <number, color>
        vector <pair <int, bool>> table;
        rep (i, n) {
            int a;
            cin >> a;
            if (i == 0) {
                table.emplace_back(1, a);
                continue;
            }
            if (i % 2 != 0 && table.back().second != a) {
                if (table.size() == 1) {
                    table.front().first++;
                    table.front().second = a;
                }
                else {
                    int tmp = table.back().first;
                    table.pop_back();
                    table.back().first += tmp + 1;
                }
            }
            else {
                if (table.back().second == a) {
                    table.back().first++;
                }
                else {
                    table.emplace_back(1, a);
                }
            }
        }

        int cnt = 0;
        for (auto i : table) if (i.second == 0) cnt += i.first;
        cout << cnt << endl;
    }
    return 0;
}
