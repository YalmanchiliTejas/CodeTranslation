#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a, b, c, x, y, ans=0, piz;
    cin >> a >> b >> c >> x >> y;
    if(a+b<=2*c) {
        ans=a*x+b*y;
        cout << ans <<endl;
        return 0;
    }
    else ans=2*c*min(x, y);
    if(x<=y) piz=b;
    else piz=a;
    if(2*c<=piz) ans+=2*c*abs(x-y);
    else ans+=piz*abs(x-y);
    cout << ans <<endl;
    return 0;
}