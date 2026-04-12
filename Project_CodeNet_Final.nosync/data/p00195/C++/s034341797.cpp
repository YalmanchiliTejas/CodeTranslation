#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int A1, A2, B1, B2, C1, C2, D1, D2, E1, E2;
    while (cin >> A1 >> A2, (A1 || A2)) {
        cin >> B1 >> B2 >> C1 >> C2 >> D1 >> D2 >> E1 >> E2;
        int mx = 0;
        string res = "";
        if (mx < A1 + A2) {
            mx = A1 + A2;
            res = "A";
        }
        if (mx < B1 + B2) {
            mx = B1 + B2;
            res = "B";
        }
        if (mx < C1 + C2) {
            mx = C1 + C2;
            res = "C";
        }
        if (mx < D1 + D2) {
            mx = D1 + D2;
            res = "D";
        }
        if (mx < E1 + E2) {
            mx = E1 + E2;
            res = "E";
        }
        cout << res << " " << mx << endl;
    }
    return 0;
}