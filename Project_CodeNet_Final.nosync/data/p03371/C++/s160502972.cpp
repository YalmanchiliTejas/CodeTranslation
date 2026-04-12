#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;

    if(A+B<=2*C) cout << A*X+B*Y << endl;
    else{
        int ans=2*C*min(X,Y);
        int S;
        if(X<Y) S=B; //足りないピザの値段
        else S=A;

        if(S<2*C) ans+=S*(max(X,Y)-min(X,Y));
        else ans+=2*C*(max(X,Y)-min(X,Y));

        cout << ans << endl;
    }
}