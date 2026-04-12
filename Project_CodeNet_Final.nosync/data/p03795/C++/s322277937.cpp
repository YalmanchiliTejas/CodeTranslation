#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, n, x, y;
    cin >> n;
    a = n/15;
    x = 800*n;
    y = x - (200*a);
    cout << y << endl;
    return 0;
}
