#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t X,Y,Z;
    int64_t ans;

    cin >> X >> Y >> Z;
    ans = X/(Y+Z);
    if((X % (Y+Z)) < Z)
        ans--;
    cout << ans << "\n";
    return 0;
}
