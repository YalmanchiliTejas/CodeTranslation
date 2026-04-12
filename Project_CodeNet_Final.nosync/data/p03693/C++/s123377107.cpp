#include <iostream>

using namespace std;

#define YES(n) cout << (n?"YES":"NO")<<endl;
#define Yes(n) cout << (n?"Yes":"No")<<endl;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    YES((a * 100 + b * 10 + c) % 4 == 0);
}