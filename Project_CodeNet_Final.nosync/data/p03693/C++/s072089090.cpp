#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,g,b;
    cin >> r >> g >> b;
    if((g*10+b)%4) cout << "NO" << "\n";
    else cout << "YES" << "\n";

    return 0;
}