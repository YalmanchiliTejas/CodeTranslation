#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, mul ;
    cin >> a >> b >> c ;
    mul = (a*100) + (b*10) + c ;
    if(mul % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}