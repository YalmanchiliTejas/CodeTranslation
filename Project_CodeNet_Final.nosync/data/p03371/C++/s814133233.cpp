#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;

    if((a+b)>=2*c) ans += 2*c*min(x,y);
    else ans += (a+b)*min(x,y);

    if(y-x>0) ans += (y-x)*min(2*c,b);
    else if(x-y>0) ans += (x-y)*min(2*c,a);

    cout << ans << endl; 
}
