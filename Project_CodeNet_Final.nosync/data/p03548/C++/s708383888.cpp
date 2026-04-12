#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z;
    cin >> x >> y >> z;
    int ans = 0;
    x -= z;
    while(x > 0){
        if(x >= y+z){
            ans++;
            x -= y+z;
        }else{
            break;
        }
    }
    cout << ans << endl;
}