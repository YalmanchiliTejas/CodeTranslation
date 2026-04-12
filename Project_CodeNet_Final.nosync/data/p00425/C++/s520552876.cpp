#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    int n, r;
    string s;
    vector<string> str;
    int top = 1;
    int front = 2;
    int left = 3;
    int _top, _left, _front;
    while (cin >> n, n != 0) {
        top = 1;
        front = 2;
        left = 3;
        int res = 1;
        for (int i = 0; i < n; i++) {
            cin >> s;
            _top = top;
            _left = left;
            _front = front;
            if (s == "North") {
                _top = front;
                _front = 7 - top;
            }
            if (s == "East") {
                _top = 7 - left;
                _left = top;
            }
            if (s == "West") {
                _top = left;
                _left = 7 - top;
            }
            if (s == "South") {
                _top = 7 - front;
                _front = top;
            }
            if (s == "Right") {
                _left = 7- front;
                _front = left;
            }
            if (s == "Left") {
                _left = front;
                _front = 7 - left;
            }
            top = _top;
            left = _left;
            front = _front;
            res += top;
        }
        cout << res << endl;
    }
}