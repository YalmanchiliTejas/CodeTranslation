#include<iostream>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    long long ans = 0;
    if(x<y){
        int tmp=x;
        x = y;
        y = tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    if(a+b > 2*c){
        ans += y*c*2;
        x -=y;
        if(a>2*c){
            ans += x*2*c;
        }
        else{
            ans += x*a;
        }
    }
    else{
        ans += x*a+y*b;
    }
    cout << ans <<endl;
    return 0;
}