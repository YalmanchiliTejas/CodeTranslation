#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    int x = N * 800;
    int y = (N / 15) * 200;
    cout << (x - y) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
