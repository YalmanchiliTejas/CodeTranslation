#include <bits/stdc++.h>

using namespace std;

const int HUGEI = 2147483647;  // (1 << 31) - 1
const long long HUGEL = 9223372036854775807;  // (1 << 63) - 1
const string ABC = "abcdefghijklmnopqrstuvwxyz";

int main(void) {
    int n;
    vector <int> an;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        an.push_back(a);
    }
    deque <int> bn;
    for (int i = 0; i < n; i++) {
        if ((n - (i + 1)) % 2 == 0) {
            bn.push_front(an[i]);
        } else {
            bn.push_back(an[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << bn[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
