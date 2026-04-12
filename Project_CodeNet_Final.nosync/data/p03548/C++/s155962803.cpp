#include<bits/stdc++.h>

using namespace std;

int main(void){
    int x, y, z;
    cin >> x >> y >> z;
    int n = x / (y+z);
    if(x % (y+z) >= z) cout << n << endl;
    else cout << n-1 << endl;
    return 0;
}