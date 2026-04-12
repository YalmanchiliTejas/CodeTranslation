#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y,ans=0,her;
    cin >> a >> b >> c >> x >> y;
    if(x>y) her = a;
    else her = b;
    if(2*c >= a+b){
        ans=a*x+b*y;
        cout << ans << '\n';
        return 0;
    }
    ans = 2 * c * min(x,y);
    ans+= (max(x,y)-min(x,y)) * min(2*c,her);
    cout << ans << '\n';
}
