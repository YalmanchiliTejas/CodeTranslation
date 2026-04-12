#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    int ans = 0;
    cin >> a >> b >> c >> x >> y;
    if(a+b>=2*c){
        if(x>y){
            ans = min(c*2*x,c*y*2 + (x-y)*a);
        }
        else{
            ans = min(c*2*y,c*x*2 + (y-x)*b);
        }
    }
    else{
        ans = a*x + b*y;
    }
    cout << ans << endl;
    return 0;
}