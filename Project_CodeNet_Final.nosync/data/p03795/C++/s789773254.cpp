#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = (n*800) - ((n/15) * 200);
    if(n >= 15) cout << res << endl;
    else cout << n*800 << endl;
    return 0;
}