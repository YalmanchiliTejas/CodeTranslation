#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll N,r,g,b;
    cin >> r >> g >> b;
    N = 100*r + 10*g + b;
    
    cout << ((N%4 == 0) ? "YES" : "NO") << "\n";
    return 0;
}
