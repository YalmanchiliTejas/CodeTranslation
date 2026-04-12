#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    int num = a * 100 + b * 10 + c;
    if(num % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}