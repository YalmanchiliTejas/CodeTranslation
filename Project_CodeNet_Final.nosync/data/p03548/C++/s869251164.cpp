#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x, y, z;
    cin >> x >> y >> z;
    long long c = 0;
    x -= z;
    while (x >= y+z) {
        c++;
        x -= (y+z);
    }
    cout << c << endl;
    return 0;   
}


