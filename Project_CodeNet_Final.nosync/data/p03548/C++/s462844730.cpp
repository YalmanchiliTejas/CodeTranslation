#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int X, Y, Z;
    cin >> X >> Y >> Z;

    int re = X - Z;
    int ans = re / (Y+Z);
    int amari = re % (Y+Z);

    if(amari >= Y+Z){
        cout << ans+1 << endl;
    }else{
        cout << ans << endl;
    }
    

    return 0;
}