#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = INT_MAX;
    for(int ab = 0; ab <= 201010; ab++){
        int cost = ab * C;
        int x = X - ab/2;
        int y = Y - ab/2;
        if(0 < x) cost += x*A;
        if(0 < y) cost += y*B;
        ans = min(ans,cost);
    }
    cout << ans << endl;
    return 0;
}