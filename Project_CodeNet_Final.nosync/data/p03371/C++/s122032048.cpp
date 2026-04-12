#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

int A,B,C,X,Y,ans;

int main(void){
    cin >> A >> B >> C >> X >> Y;
    if(X<Y){swap(A,B);swap(X,Y);}
    
    if(A+B > 2*C)ans += 2*C*Y;
    else ans +=(A+B)*Y;
    X -=Y;Y=0;
    ans += min(2*C*X,A*X);    

    cout << ans << endl;
}
