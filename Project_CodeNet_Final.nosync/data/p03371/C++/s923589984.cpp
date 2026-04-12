#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n); ++i)
using namespace std;

typedef long long LL;

int main(void){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    LL ans = a * x + b * y,sum = ans;
    int tmp = 0;
    if(x > y){
        int i = 1;
        for(i = 1;i <= y;i++){
            tmp = sum - (a+b) * i;
            tmp += 2*c*i;
            if(tmp < ans)ans = tmp;
        }
        for(i = y+1;i <= x;i++){
            tmp = sum - a * i - b * y;
            tmp += 2*c*i;
            if(tmp < ans)ans = tmp;
        }
    }else{
        int i = 1;
        for(i = 1;i <= x;i++){
            tmp = sum - (a+b) * i;
            tmp += 2*c*i;
            if(tmp < ans)ans = tmp;
        }
        for(i = x+1;i <= y;i++){
            tmp = sum - b * i - a * x;
            tmp += 2*c*i;
            if(tmp < ans)ans = tmp;
        }
    }
    cout << ans << endl;
}