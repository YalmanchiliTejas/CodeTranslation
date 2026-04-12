#include<bits/stdc++.h>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    if (((X/(Y+Z))*(Y+Z))+Z <= X) cout << X/(Y+Z) << "\n";
    else cout << X/(Y+Z)-1 << "\n";
}