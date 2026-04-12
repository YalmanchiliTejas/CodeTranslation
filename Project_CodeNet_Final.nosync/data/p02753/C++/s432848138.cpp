#include <iostream>
#include <vector>
using namespace std;
int main() {
    string s;
    cin >> s;
    if (s.find("B") == std::string::npos ||
        s.find("A") == std::string::npos) cout << "No";
    else cout << "Yes";
    return 0;
}