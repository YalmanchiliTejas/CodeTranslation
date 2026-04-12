#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string ansFizzBuzz(int n) {
    string result;
    if (n % 15 == 0) {
        result = "FizzBuzz";
    } else if (n % 3 == 0) {
        result = "Fizz";
    } else if (n % 5 == 0) {
        result = "Buzz";
    } else {
        stringstream ss;
        ss << n;
        ss >> result;
    }
    return result;
}

int main() {
    while (true) {
        int m, n;
        cin >> m >> n;
        if ((m | n) == 0) {
            break;
        }
        vector<int> players(m);
        for (int i = 0; i < m; i++) {
            players[i] = i + 1;
        }
        vector<string> lines(n);
        for (int i = 0; i < n; i++) {
            cin >> lines[i];
        }
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (players.size() <= 1) {
                break;
            }
            if (lines[i] != ansFizzBuzz(i + 1)) {
                players.erase(players.begin() + pos);
            } else {
                pos++;
            }
            pos = pos % players.size();
        }
        string result;
        for (vector<int>::iterator it = players.begin(); it != players.end(); it++) {
            stringstream ss;
            ss << *it;
            result += " " + ss.str();
        }
        result.erase(0, 1);
        cout << result << endl;
    }
}