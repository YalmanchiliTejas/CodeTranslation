#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    x -= 2*z+y;
    cout << (x / (y+z))+1 << endl;
}