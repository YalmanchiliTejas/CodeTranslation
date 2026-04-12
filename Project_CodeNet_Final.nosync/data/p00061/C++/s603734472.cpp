#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Team {
    int id, point, rank;

    bool operator<(const Team& right) const {
        return point > right.point;
    }
} team[100];

int main() {
    int id, point, n = 0;
    while (1) {
        scanf("%d,%d", &id, &point);
        if (id == 0) {
            break;
        }
        team[id - 1].id = id;
        team[id - 1].point = point;
        n++;
    }
    sort(team, team + n);
    team[0].rank = 1;
    for (int i = 1, rank = 1; i < n; i++) {
        if (team[i].point == team[i - 1].point) {
            team[i].rank = rank;
        }
        else {
            team[i].rank = ++rank;
        }
    }
    while (cin >> id) {
        for (int i = 0; i < n; i++) {
            if (team[i].id == id) {
                cout << team[i].rank << endl;
                break;
            }
        }
    }

    return 0;
}