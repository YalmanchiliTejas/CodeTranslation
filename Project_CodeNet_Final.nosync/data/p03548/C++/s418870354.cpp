#include <bits/stdc++.h>
using namespace std;
int main(){

    long long int X,Y,Z,i;
    cin >> X >> Y >> Z;

    for(i = 0; i < 100000000; i++) {

        if(Z + (Y + Z) * i > X) {
            break;
        }
    }

    cout << i - 1 << endl;

    return 0;
}
