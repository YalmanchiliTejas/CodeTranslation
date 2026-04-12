#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    if (n - m > 0) cout << "No" << endl;
    else if (n - m == 0) cout << "Yes" << endl;
    return 0;
}