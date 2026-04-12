#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int i = 1;
    int ans = 0;
    while(y*i+z*(i+1) <= x) {
        ans++;
        i++;
    }
    
    cout << ans << endl;
}
