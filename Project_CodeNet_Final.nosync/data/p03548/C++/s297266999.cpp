#include<bits/stdc++.h>
using namespace std;

int main(){
    int X,Y,Z;
    cin >> X >> Y >> Z;
    int count = 0;
    int s = Z;
    while(s + Y <= X - Z){
        count++;
        s += Y + Z;
    }
    cout << count << endl;
}