#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    
    int sum = 100 * r + 10 * g + b;
    
    if ( sum % 4 == 0 ) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}