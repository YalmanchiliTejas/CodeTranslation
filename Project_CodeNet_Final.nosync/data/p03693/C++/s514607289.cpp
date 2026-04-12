#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
using namespace std;
#define pi M_PI

int main(){
    int r, g, b, ans = 0;
    cin >> r >> g >> b;
    ans = 100*r + 10*g + b;

    if(ans%4 == 0){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    
    return 0;
}