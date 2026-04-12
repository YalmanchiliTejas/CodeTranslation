#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    if((a * 100 + b * 10 + c) % 4){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
    }
    return 0;
}
