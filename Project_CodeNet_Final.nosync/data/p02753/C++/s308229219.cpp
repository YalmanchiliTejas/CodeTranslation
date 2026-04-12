#include<iostream>
using namespace std;

int main() {
    // 整数の入力
    string s;
    cin >> s;

    if (s.compare("AAA") == 0 || s.compare("BBB") == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}