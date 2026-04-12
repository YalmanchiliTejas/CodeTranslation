#include <iostream>

using namespace std;

int main(){
    int x,y,z;

    cin >> x >> y >> z;
    x -= z;
    int ans;
    ans = x/(y+z);
    cout << ans << '\n';
}