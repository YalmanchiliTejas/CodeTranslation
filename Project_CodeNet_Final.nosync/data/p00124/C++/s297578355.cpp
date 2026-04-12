#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
    bool insertLinefeed = false;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        multimap<int, string> teams;
        set<int> scores;
        for (int i = 0; i < n; i++) {
            string team;
            int win, lose, draw;
            cin >> team >> win >> lose >> draw;
            teams.insert(make_pair(3 * win + draw, team));
            scores.insert(3 * win + draw);
        }
        if (insertLinefeed) {
            cout << endl;
        } else {
            insertLinefeed = true;
        }
        for (set<int>::reverse_iterator sit = scores.rbegin(); sit != scores.rend(); sit++) {
            for (multimap<int, string>::iterator it = teams.lower_bound(*sit); it != teams.upper_bound(*sit); it++) {
                cout << it->second << "," << it->first << endl;
            }
        }
    }
}