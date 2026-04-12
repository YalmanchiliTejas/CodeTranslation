#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool calc(bool a, bool b) {
    if (a && !b) return false;
    else return true;
}

int main() {
    int N; cin >> N;
    vector<bool> a(N);
    for (int i = 0; i < N; ++i) {
        string s; cin >> s;
        if (s == "T") a[i] = true;
        else a[i] = false;
    }
    bool res = calc(a[0], a[1]);
    for (int i = 2; i < N; ++i) {
        res = calc(res, a[i]);
    }
    if (res) cout << "T" << endl;
    else cout << "F" << endl;
}

