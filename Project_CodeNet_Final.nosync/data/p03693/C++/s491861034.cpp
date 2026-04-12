#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if ((100*a+10*b+c) % 4 == 0) cout << "YES\n";
    else cout << "NO\n";
}
