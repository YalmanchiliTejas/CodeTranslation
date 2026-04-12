#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll nmny=a*x+b*y;
    ll m=min(x,y);
    ll M=max(x,y);
    ll ahmny=M*2*c;
    ll price=0;
    ll num;
    if(x<y){
        price=b;
        num=x;
    }
    else {
        price=a;
        num=y;
    }
    ll hmny=num*2*c+(M-m)*price;
    ll mny=min(nmny,ahmny);
    mny=min(mny,hmny);

    cout << mny;
}