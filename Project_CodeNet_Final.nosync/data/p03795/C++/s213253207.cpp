#include <iostream>

using namespace std;

int f(int n) {
    return (n * 800) - (n / 15 * 200);
}

int main() {

    int n;
    cin >> n;

    int result = f(n);
    cout << result << endl;

    return 0;
}
