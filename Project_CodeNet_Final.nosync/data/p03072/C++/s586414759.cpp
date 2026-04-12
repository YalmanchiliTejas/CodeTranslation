#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int main() {
    int n, tmp, cur = 0, out = 0;
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> tmp;
        if ( tmp >= cur ) {
            out++;
            cur = tmp;
        }
    }
    cout << out << endl;
    return 0;
}