#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long int ll;


int main(void){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 0;
    if(a+b < 2*c){
        ans += a*x + b*y;
    }
    else{
        ans += 2*c*min(x,y);
        int num = abs(x-y);
        if(x>y){
            ans += num*min(a,2*c);
        }
        else{
            ans += num*min(b,2*c);
        }
    }
    cout << ans << endl;
    
    return 0;
}


























































