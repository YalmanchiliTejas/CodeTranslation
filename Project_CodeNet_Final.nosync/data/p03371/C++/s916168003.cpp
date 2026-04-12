#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#define maxn 100003
using namespace std;

int main(){
    int a,b,c,x,y;
    int ans=0;
    cin >> a >> b >> c >> x >> y;
    if(2*c >= (a+b)){
        ans = a*x+b*y;
    }else{
        while(x>0 && y>0){
            ans+=2*c;
            x--;
            y--;
        }
        while(y > 0){
            if(2*c < b) ans += 2*c;
            else ans += b;
            y--;
        }
        while(x > 0){
            if(2*c < a) ans += 2*c;
            else ans += a;
            x--;
        }
    }
    cout << ans;
    return 0;
}
