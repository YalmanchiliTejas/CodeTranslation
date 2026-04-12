#include<iostream>
using namespace std;

int main(){
    
    int a_price;
    int b_price;
    int ab_price;

    int a_num;
    int b_num;

    int cost=0;

    cin >> a_price;
    cin >> b_price;
    cin >> ab_price;

    cin >> a_num;
    cin >> b_num;

    int flag1 = 0;  //Aピザ一枚とBピザ一枚の合計の方が小さいとき
    if(a_price+b_price>ab_price*2) flag1 = 1;

    if(a_price>2*ab_price) a_price=2*ab_price;
    if(b_price>2*ab_price) b_price=2*ab_price;
    
    int dif;
    int same;
    int flag2=0;
    if (a_num>b_num){
        dif = a_num - b_num; 
        same = b_num;
        flag2=1;
    }
    else{
        dif = b_num - a_num; 
        same = a_num;
    }

    if(flag1==0){
        cost += (a_price+b_price)*same;
        if(flag2==0){
            cost += dif*b_price;
        }
        else{
            cost += dif*a_price;
        }
    }

    else{
        cost += ab_price*2*same;
        if(flag2==0){
            cost += dif*b_price;
        }
        else{
            cost += dif*a_price;
        }
    }
    
    cout << cost;
}