#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。
int main () {
    int A , B , C , X , Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = 1e9;
    for(int i = 0; i <= max(X , Y); i++){
        ans = min(ans , 2 * i * C + max(0 , X - i) * A + max(0 , Y - i) * B);
    }
    cout << ans << endl;
    return 0;
}
