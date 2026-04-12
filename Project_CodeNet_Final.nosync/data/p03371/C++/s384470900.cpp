#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int a = X;
    int b = Y;
    int min = A * a + B * b;
    while (a > 0 || b > 0) {
        int tmp = min + C * 2 - (a > 0 ? A : 0) - (b > 0 ? B : 0);
        if (min < tmp) break;
        min = tmp;
        --a; --b;
    }
    cout << min << '\n';
    return 0;
}
