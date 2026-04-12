#include<bits/stdc++.h>
using namespace std;

int main(){
   int A, B, C, X, Y;
   cin >> A >> B >> C >> X >> Y;
    int ans = 1000000000;
   for(int i = 0; i <= 2 * max(X, Y); i += 2) {
       int a = i / 2;
       int b = i / 2;
       int a1 = X - a;
       int a2 = Y - b;
       if(a1 < 0) a1 = 0;
       if(a2 < 0) a2 = 0;
    if(ans > C * i + a1 * A + a2 * B) ans = C * i + a1 * A + a2 * B;
       }

    cout << ans;
    return 0;
}