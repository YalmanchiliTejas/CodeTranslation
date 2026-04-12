#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y,a1,a2,a3,ans;
    cin >> a >> b >> c >> x >> y;
    int m = min(x,y);
    a1 = c*2*m+a*(x-m)+b*(y-m);
    a2 = a*x+b*y;
    a3 = max(x,y)*2*c;
    ans = min(a1,a2);
    cout << min(ans,a3) << endl;
}