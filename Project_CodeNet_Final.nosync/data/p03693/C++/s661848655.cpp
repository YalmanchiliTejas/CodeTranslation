#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int res = a * 100 + b * 10 + c;
    cout << (res % 4 == 0 ? "YES" : "NO");

	return 0;
}
