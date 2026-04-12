#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,x,y;
    int64_t value = 1000000000;
    cin >> a >> b >> c >> x >> y;
    for(int i = 0;i <= 2*max(x,y);i+=2){
        int a_,b_;
        if(x-(i/2) >= 0){
            a_ = x-(i/2);
        }else{
            a_ = 0;
        }
        if(y-(i/2) >= 0){
            b_ = y-(i/2);
        }else{
            b_ = 0;
        }
        value = min(value,(int64_t)(a_*a+b_*b+c*i));
    }
    cout << value;
    return 0;
}