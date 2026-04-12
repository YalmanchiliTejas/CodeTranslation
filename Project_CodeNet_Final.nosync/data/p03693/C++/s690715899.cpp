#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char r, g, b;
    cin >> r >> g >> b;
    string s;
    s += r;
    s += g;
    s += b;
    int n = stoi(s);
    if(n%4 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
