#include <iostream>
using namespace std;

int main(void){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int ans = (X - Z) /(Y + Z);
    cout << ans << endl;
    return 0;
}