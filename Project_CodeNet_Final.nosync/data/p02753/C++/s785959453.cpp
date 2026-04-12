#include <iostream>
#include <set>

using namespace std;

int main() {
    string S;
    set<char> s;
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        s.insert(S[i]);
    }
    if (s.size() == 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}
