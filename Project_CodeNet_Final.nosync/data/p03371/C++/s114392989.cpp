#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = A*X+B*Y;
    for (int i = 0; i <= max(X,Y); i++) {
        if (C*2*i+(X-i)*A+(Y-i)*B < ans) {
            if((X-i)*A < 0 || (Y-i)*B < 0) {
                if(C*2*i+(X-i)*A+(Y-i)*B-min((X-i)*A,(Y-i)*B) < ans) {
                    ans = C*2*i+(X-i)*A+(Y-i)*B-min((X-i)*A,(Y-i)*B);
                }
            }
            else {
            ans = C*2*i+(X-i)*A+(Y-i)*B;
            }
        }
    }
    cout << ans << endl;
}