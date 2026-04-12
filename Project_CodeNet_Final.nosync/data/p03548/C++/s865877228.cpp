#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    int X,Y,Z,tmp,ans;
    cin >> X >> Y >> Z;
    ans = X / (Y + Z);
    if (X % (Y + Z) < Z) ans--;
    cout << ans << endl;
    return 0;
}
