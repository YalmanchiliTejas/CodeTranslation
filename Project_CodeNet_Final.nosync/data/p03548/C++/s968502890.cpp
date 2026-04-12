#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;

int main(void)
{
    int X, Y, Z;
    cin >> X >> Y >> Z;

    X -= Z;
    int ans = X / (Y + Z);
    cout << ans << endl;
    return (0);
}