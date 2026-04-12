#include<bits/stdc++.h>
using namespace std;

int main(void){

    int x, y, z; cin >> x >> y >> z;
    int ans = 0;
    
    x -= z;

    while(x >= y+z){
        ans++;
        x -= y+z;
    }

    cout << ans << endl;

    return 0;
}
