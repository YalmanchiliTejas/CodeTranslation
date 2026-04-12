#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r,b,g;

    cin >> r >> b >> g;

    int x = (r*10+b)*10+g;

    if(x%4==0)
    {
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}
