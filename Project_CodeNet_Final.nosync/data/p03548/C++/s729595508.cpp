#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int X,Y,Z;
    cin >> X >> Y >> Z;
    //X:横幅
    //Y:人の幅
    //Z:必要な間隔
    int person=0;
    X -= Z;
    while(X >= Y+Z){
        X -= Y;
        X -= Z;
        person++;
    }
    cout << person << endl;
}