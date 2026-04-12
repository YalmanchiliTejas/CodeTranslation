#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){

    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = 1<<30;
    for(int i=0;i<=100000;i++){
        ll n = i*2*C+max(0, X-i)*A+max(0, Y-i)*B;
        ans = min(ans, n);
    }
    cout << ans << endl;
}
