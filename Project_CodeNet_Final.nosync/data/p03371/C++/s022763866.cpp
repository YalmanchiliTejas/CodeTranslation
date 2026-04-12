#include<bits/stdc++.h>
using namespace std;
int main(){
    long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    long ans = 0;
    while(x>0 && y>0){
        x--;
        y--;
        ans += min(a+b,2*c);
    }
    if(x>0){
        while(x>0){
            x--;
            ans += min(a,2*c);
        }
    }

    if(y>0){
        while(y>0){
            y--;
            ans += min(b,2*c);
        }
    }
    cout << ans << endl;
}
