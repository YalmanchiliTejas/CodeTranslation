#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    if((r * 100 + g * 10 + b) % 4 != 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    return 0;
}