#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int ab = 2*c;
    int ans = 0;
    if(a+b>ab){
        while(x>0 && y>0){
            x--;
            y--;
            ans += ab;
        }
        if(x>0){
            if(a>ab){
                while(x>0){
                    x--;
                    ans += ab;
                }
            }else{
                while(x>0){
                    x--;
                    ans += a;
                }
            }
        }else if(y>0){
            if(b>ab){
                while(y>0){
                    y--;
                    ans += ab;
                }
            }else{
                while(y>0){
                    y--;
                    ans += b;
                }
            }
        }
    }else{
        ans = a*x + b*y;
    }
    cout << ans << endl;
    return 0;
}