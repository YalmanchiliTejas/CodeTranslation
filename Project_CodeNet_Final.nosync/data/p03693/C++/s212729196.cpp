#include <bits/stdc++.h>
using namespace std;
int x, y, flag;

int main() {
    string r,g,b;
    cin >> r >> g >> b;
    string s = r + g + b;
    if(stoi(s)%4==0)
        cout << "YES" << endl;
    else
        cout << "NO" <<endl;
}
