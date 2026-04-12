#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void YesNo(bool x) {
    cout << (x ? "Yes" : "No") << endl;
}

int main() {
    string s;
    cin >> s;
    YesNo(!(s == "AAA" || s == "BBB"));
    return 0;
}