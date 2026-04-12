#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include "iomanip"

using namespace std;

int main() {
    string t = "aeiou";
    char s;
    cin >> s;
    for (char c : t) {
        if (c == s) {
            cout << "vowel";
            return 0;
        }
    }
    cout << "consonant";
    return 0;
}

