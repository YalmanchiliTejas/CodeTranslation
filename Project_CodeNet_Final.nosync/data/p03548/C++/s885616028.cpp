#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main(void){
    // Your code here!
    int X,Y,Z;
    cin >> X >> Y >> Z;
    X -= Z;
    int ans = 0;
    ans += X / (Y + Z);
    cout << ans << endl;
}
