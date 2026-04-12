#include <iostream>
#include <algorithm>
using namespace std;

struct Team {
    int id, point;
    string name;
    bool operator<(const Team& other) const {
        return point == other.point
               ? id < other.id
               : point > other.point;
    }
};

int main() {
    int n;
    bool first = true;

    while (cin >> n, n) {
        Team team[10];
        if (!first) cout << endl; first = false;
        for (int i = 0; i < n; i++) {
            int w, l, d;
            team[i].id = i;
            cin >> team[i].name >> w >> l >> d;
            team[i].point = w*3 + d;
        }
        sort(team, team+n);
        for (int i = 0; i < n; i++) {
            cout << team[i].name << "," << team[i].point << endl;
        }
    }
    return 0;
}