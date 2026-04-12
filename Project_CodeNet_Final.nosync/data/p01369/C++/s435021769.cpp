#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

bool left_[26];
const char* left_str = "abcdefgqrstvwxz";

inline bool isLeft(char c)
{
    return left_[c - 'a'];
}

int main()
{
    for (int i = 0; i < 15; i++) {
        left_[left_str[i] - 'a'] = true;
    }
    while (true) {
        string str;
        cin >> str;
        if (str.size() == 1 and str[0] == '#') {
            break;
        }
        bool l = isLeft(str[0]);
        int cnt = 0;
        for (int i = 1; i < str.size(); i++) {
            bool l2 = isLeft(str[i]);
            if (l != l2) {
                cnt++;
                l = l2;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}