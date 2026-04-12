#include <bits/stdc++.h>
using namespace std;

int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int ans = 0;

    while(true){
        if(ans * Y + (ans + 1) * Z > X ){
            break;
        }
        ans++;
    }

    cout << ans - 1 << endl;

} 