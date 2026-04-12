#include "bits/stdc++.h"

using namespace std;

void Main() {
    int r, g, b;
    cin >> r >> g >> b;

    int n = r * 100 + g * 10 + b;
    cout << (n % 4 == 0 ? "YES" : "NO") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
