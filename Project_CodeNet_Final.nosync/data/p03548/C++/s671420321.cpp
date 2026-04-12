#include<bits/stdc++.h>
using namespace std;
int main(){
    int X,Y,Z;
    cin >> X >> Y >> Z;
    X = X - Z;
    int human = Y+Z;
    int c = 0;
    while(X>=0){
        X -= human;
        c++;
    }
    cout << c-1 << endl;
}