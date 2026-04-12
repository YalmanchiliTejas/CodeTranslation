#include<bits/stdc++.h>
using namespace std;

int main(){
        int A,B,C,X,Y;
        cin >> A>>B>>C>>X>>Y;
        int ans;
        if((A+B) > (C*2))
        {
                int p,q;
                int cbuy1 = min(X, Y);
                p = C*2*cbuy1;
                p+=A * (X - cbuy1) + B * (Y - cbuy1);

                int cbuy2 = max(X, Y);
                q= C*2*cbuy2;

                ans = min(p,q);
        }
        else
        {
                ans = A*X + B*Y;
        }

        cout << ans << endl;

}
