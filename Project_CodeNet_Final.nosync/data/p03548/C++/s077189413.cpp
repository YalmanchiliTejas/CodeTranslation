#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int x, y, z;
    cin >> x >> y >> z;

    if(x%(y+z) != 0){
        if(x%(y+z) >= z) cout << x/(y+z) << endl;
        else cout << (x/(y+z))-1 << endl;
    } 
    else cout << (x/(y+z))-1 << endl;

    return 0;
}