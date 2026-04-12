#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;
    string ans;
    if (S == "AAA" || S == "BBB") {
        ans = "No";
    } else {
        ans = "Yes";
    }
    cout << ans << "\n";
    return 0;
}
