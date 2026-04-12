#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    int ans = (x - z) / (y + z);
    
    cout << ans;

    return 0;
}