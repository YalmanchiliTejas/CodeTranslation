#include<bits/stdc++.h>
using namespace std;
int main(){
    int X,Y,Z,a,b = 0;
    cin >> X >> Y >> Z;
    for(int i = 1; i < X; i++){
        a = i*Y +(i + 1)*Z;
        if(a > X)
        {
            break;
        }
        b++;
    }
    cout << b << endl;
}