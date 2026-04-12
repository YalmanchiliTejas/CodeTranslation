#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;

    if(a+b > 2*c){
        while(x > 0 && y > 0){
            ans += 2*c;
            x--;
            y--;
        }
        while(x > 0){
            ans += min(a, 2*c);
            x--;
        }
        while(y > 0){
            ans += min(b, 2*c);
            y--;
        }
    }else{
        ans += a*x + b*y;
    }
    
    cout << ans << endl;

    return 0;
}
