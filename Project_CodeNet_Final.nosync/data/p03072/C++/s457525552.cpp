#include <iostream>

using namespace std;

int max(int a, int b) {
    if (a>b) return a;
    else return b;
}

int main(void) {
    int i, N, H[30], m, X;
    cin >> N;
    for (i=0;i<N;i++) cin >> H[i];
    m = H[0];
    X = 1;
    for (i=1;i<N;i++) {
        if (m<=H[i]) X++;
        m = max(m,H[i]);
    }

    cout << X << endl;

    return 0;
}