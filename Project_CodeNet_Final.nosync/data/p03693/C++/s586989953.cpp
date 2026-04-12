#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#define _USE_MATH_DEFINENS
#include <cmath>
using namespace std;

#define p(x) cout << x << endl;
#define el cout << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int r, g, b;
    cin >> r >> g >> b;
    int ans = r * 100 + g * 10 + b;
    if(ans % 4 == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    el;
}
