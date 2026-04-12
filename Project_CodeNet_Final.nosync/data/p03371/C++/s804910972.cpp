#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    long long int A,B,C,X,Y,Z;
    cin >> A >> B >> C >> X >> Y;
    Z = 0;
    long long int ans = 9876543210;
    for(int i = 0;i < 100001;i++){
      ans = min(ans,2*i*C+A*max(Z,X-i)+B*max(Z,Y-i));
    }
    cout << ans << endl;
}