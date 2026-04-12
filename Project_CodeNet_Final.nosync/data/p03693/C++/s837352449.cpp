#include<iostream>
#include <algorithm>
#include <string>
#include<math.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    a *= 100;
    b *= 10;
    if ((a + b + c) % 4 == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
