#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    cout << (s[0] != s[1] || s[1] != s[2] ? "Yes" : "No") << endl;
    return 0;
}