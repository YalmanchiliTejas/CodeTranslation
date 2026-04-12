#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

void inv(vector<int>& v) {
    int length = v.size();
    for (int i = 0; i < length; i++) {
        cin >> v[i];
    }
}
void inv(vector<int>& v, int length) {
    for (int i = 0; i < length; i++) {
        cin >> v[i];
    }
}

int main() {
    int x;
    cin >> x;

    if (x >= 30) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
