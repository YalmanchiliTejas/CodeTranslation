#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int i, w;
    for(i=1;;i++){
        w = Y*i + Z*(i-1) + 2*Z;
        if(w > X){
            i--;
            break;
        }

    }

    cout << i << endl;

}