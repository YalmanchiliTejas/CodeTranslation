#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int x,y,z,ans = 0;
    cin >> x >> y >> z;

    x -= z;

    while(x >= y+z){
        ans++;
        x -= (y+z);
    }

    cout << ans << endl;

    return 0;
}