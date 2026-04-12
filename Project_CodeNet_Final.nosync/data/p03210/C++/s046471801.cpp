#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    int X;
    cin >> X;

    if(X == 3 || X == 5 || X == 7) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    cout << endl;
    return 0;
}