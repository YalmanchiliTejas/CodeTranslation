#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    if((100*r+10*g+b)%4 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
     return 0;
}

