#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c,x,y;
    cin >> a >> b >> c;
    cin >> x >> y;
    
    long long int l,m,n;
    long long int ans;
    
    if(x>=y){
        l = a*x + b*y;
        m = c*2*y + a * (x-y);
        n = c*2*x;
        ans = min({l,m,n});
    }else{
        l = a*x + b*y;
        m = c*2*x + b * (y - x);
        n = c*2*y;
        ans = min({l,m,n});
    }
    cout << ans << endl;
}
