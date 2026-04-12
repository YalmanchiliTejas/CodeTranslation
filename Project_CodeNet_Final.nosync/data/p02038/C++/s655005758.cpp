#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int n;
    char a, b;
    cin >> n;
    cin >> a;
    for (int i = 1; i < n; i++) {
        cin >> b;
        if (b == 'F' && a == 'T') a = 'F';
        else a = 'T';
    }
    cout << a << endl;
    return 0;
}
