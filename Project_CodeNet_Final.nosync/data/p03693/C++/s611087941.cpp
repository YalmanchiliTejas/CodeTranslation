#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    int s = r*100 + g*10 + b;
    
    cout << (s%4? "NO": "YES") << endl;
    
    return 0;
}