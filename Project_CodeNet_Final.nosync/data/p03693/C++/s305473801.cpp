#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    int x = stoi(s);
    cout << (x % 4 == 0 ? "YES" : "NO") << endl;
}
