#include <iostream>
#include <string>
#include <list>
#include <sstream>
using namespace std;

string toStr(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

int main() {
    int m, n;
    while (cin >> m >> n, m) {
        list<int> player;
        for (int i=1; i<=m; ++i) {
            player.push_back(i);
        }
        list<int>::iterator it = player.begin();
        string s, expected;
        for (int i=1; i<=n; ++i) {
            cin >> s;
            if (i % 15 == 0) {
                expected = "FizzBuzz";
            } else if (i % 5 == 0) {
                expected = "Buzz";
            } else if (i % 3 == 0) {
                expected = "Fizz";
            } else {
                expected = toStr(i);
            }
            if (s == expected) {
                ++ it;
            } else if (1 < (int)player.size()) {
                it = player.erase(it);
            }
            if (it == player.end()) {
                it = player.begin();
            }
        }
        for (it = player.begin(); it != player.end(); ++it) {
            cout << (it == player.begin() ? "" : " ") << *it;
        }
        cout << endl;
    }
    return 0;
}