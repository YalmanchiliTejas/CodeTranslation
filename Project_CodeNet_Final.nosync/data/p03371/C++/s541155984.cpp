#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

long long gcd(long long aaa,long long bbb) {
    if(bbb==0) {
        return aaa;
    }
    return gcd(bbb,aaa%bbb);
}

int main (){

    ll A,B,C,X,Y,tmp=0,ans=0,d=0;
    cin >> A >> B >> C >> X >> Y;
    
    tmp = X-Y;
    d = min(A+B,2*C);
    ans += min(X,Y) * d;
    if(tmp > 0) {
        ans += tmp*min(A,C*2);
    }else if(tmp < 0) {
        ans += abs(tmp)*min(B,C*2);
    }
    cout << ans << endl;

    return 0;
}
