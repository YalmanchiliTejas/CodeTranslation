#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define big 1000000007
int main(){
    int a,b,c,x,y;
    cin >>a>>b>>c>>x>>y;
    int sum=0;
    if(a+b>2*c){//aピザとbピザを1枚ずつ買うより、ABピザを2枚買ったほうが安い
        if(x>=y){
            sum += 2*c*y;
            x -= y;
            if(a<2*c){
                sum += a*x;
            }
            else{
                sum += 2*c*x;
            }
        }
        else{
            sum += 2*c*x;
            y -= x;
            if(b<2*c){
                sum += b*y;
            }
            else{
                sum += 2*c*y;
            }            
        }
    }
    else{
        sum = a*x+b*y;
    }
    cout<<sum<<endl;
}