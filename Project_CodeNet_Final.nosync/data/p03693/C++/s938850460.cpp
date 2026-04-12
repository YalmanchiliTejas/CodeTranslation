#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int r,g,b;
    cin >>r>>g>>b;
    if((g*10+b)%4== 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

