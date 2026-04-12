#include <bits/stdc++.h>
using namespace std;
#define reup(a, b) for(int i = a; i <= b; ++i)

int main(void) {
    int x, y, z;
    while(cin >> x >> y >> z) {
        cout <<  (x - z) / (y + z) << endl;
    }
}
