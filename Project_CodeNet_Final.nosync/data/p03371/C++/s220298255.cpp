#include<iostream>

using namespace std;
int main(){
    int a,b,c,x,y,max,next,flag_x = 0,money = 0;
    cin >> a >> b >> c >> x >> y;
    if(x > y){
        max = x;
        next = y;
        flag_x++;
    }else{
        max = y;
        next =x;
    }
    if(a+b > c*2){
        money += c*2*(next);
    }else{
        money += (a+b)*(next);
    }

    if(flag_x){
        if(a>=c*2){
            money += c*2*(max-next);
        }else{
            money += a*(max-next);
        }
    }else{
        if(b>=c*2){
            money += c*2*(max-next);
        }else{
            money += b*(max-next);
        }
    }
    cout << money <<endl;
    return 0;
}