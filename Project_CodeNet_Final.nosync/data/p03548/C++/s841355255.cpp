#include "bits/stdc++.h"
using namespace std;
int main(){
    int x,y,z,n;
    cin >> x >> y >> z;
    x -= z;
    n = x / (y+z);
    cout << n << endl;
    return 0;
}