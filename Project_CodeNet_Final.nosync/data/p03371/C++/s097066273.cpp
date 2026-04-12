#include<bits/stdc++.h>
using namespace std;
int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans;
    for (int i = 0; i <= max(X, Y)*2; i+=2)
    {
        int money;
        int a, b, ab;
        ab = i;
        a = X - i/2;
        b = Y - i/2;
        if(a<0) a=0;
        if(b<0) b=0;
        money = A*a + B*b + C*ab;
        if(i == 0) ans = money;
        else if(ans > money) ans = money;
    }
    cout << ans << endl;
}