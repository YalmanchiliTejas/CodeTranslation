#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。(int64_t)
int main(){
    int X , Y , Z;
    cin >> X >> Y >> Z;
    int N = (X - Z) % (Y + Z);
    if(N == 0){
        cout << (X - Z) / (Y + Z) << endl;
    }
    else{
        if(Y >= Z){
            cout << (X - Z) / (Y + Z) << endl;
        }
        else{
            if(((X - Z) - (X - Z) / (Y + Z)) >= Y){
                cout << (X - Z) / (Y + Z) << endl;
            }
            else{
                cout << (X - Z) / (Y + Z) << endl;
            }
        }
    }
}