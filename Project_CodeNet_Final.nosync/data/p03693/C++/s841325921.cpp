#include <iostream>
using namespace std;
int main() {
    int r, g, b; cin >> r >> g >> b;
    int n = r * 100 + g * 10 + b;
    if (n % 4 == 0) printf("%s\n", "YES");
    else printf("%s\n", "NO");
}