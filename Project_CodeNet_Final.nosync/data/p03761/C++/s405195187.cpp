#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<char, int> char_appear_count;
    for (char c = 'a'; c <= 'z'; c++) {
        char_appear_count[c] = 51;
    }

    for (int i = 0; i < n; i++) {
        map<char, int> si_char_appear_count;
        for (char c = 'a'; c <= 'z'; c++) {
            si_char_appear_count[c] = 0;
        }

        string si;
        cin >> si;
        for (char si_c: si) {
            si_char_appear_count[si_c]++;
        }

        for (auto p: si_char_appear_count) {
            char_appear_count[p.first] = min(p.second, char_appear_count[p.first]);
        }
    }

    string answer;
    for (auto c_ac_pair: char_appear_count) {
        if (c_ac_pair.second == 0 || c_ac_pair.second == 51) {
            continue;
        }
        answer += string(c_ac_pair.second, c_ac_pair.first);
    }

    cout << answer << endl;
    return 0;
}
