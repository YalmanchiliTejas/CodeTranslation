#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    string ans = "NO";
    if((10 * b + c) % 4 == 0) ans = "YES";
    cout << ans;
}
