#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

void solve() {
    int x;
    cin >> x;
    if(x == 7 || x == 5 || x == 3) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    solve();
    return 0;
}