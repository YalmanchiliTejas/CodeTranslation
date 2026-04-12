#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int answer = (X - Z) / (Y + Z);
    if (answer <= X){
        cout << answer << endl;
    }
    else {
        cout << X << endl;
    }
    
}