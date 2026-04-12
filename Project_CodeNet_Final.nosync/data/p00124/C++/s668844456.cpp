#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct team {
    string name;
    int win, lose, draw;
    int point;

    bool operator<(const team& o) const {
        return (point > o.point);
    }
};

void solve(int n) {
    team teams[n];
    for (int i = 0; i < n; i++) {
        cin >> teams[i].name >> teams[i].win
            >> teams[i].lose >> teams[i].draw;
        teams[i].point = teams[i].win * 3 + teams[i].draw;
    }
    stable_sort(teams, teams+n);
    for (int i = 0; i < n; i++) {
        cout << teams[i].name << ',' << teams[i].point
             << endl;
    }
}

int main() {
    int n;
    cin >> n;
    solve(n);
    while (cin >> n) {
        if (n == 0) break;
        cout << endl;
        solve(n);
    }
    return 0;
}