#include<iostream>
using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int d = y + z;
    int a = (x % d) < z;
    cout << x / d - a << endl;
}
