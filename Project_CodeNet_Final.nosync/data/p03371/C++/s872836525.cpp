#include <iostream>

using namespace std;

int main(void){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  //ABピザ2枚組を何セット買うか
  int ab_num;
  //セットを最大で何セット買えるか  
  int set_max = max(X, Y);
 
  //ABセットを何セット買うかで総当たり的に確かめる
  //各場面でA, Bのピザを何枚買うか                                      
  int a_num, b_num;
  //priceの最大値は5000*10^5
  int price, price_min = 1000000000;
  for(ab_num=0; ab_num<=set_max; ab_num++){
    a_num = 0; b_num = 0;
    if(ab_num < X)
      a_num = X - ab_num;
    if(ab_num < Y)
      b_num = Y - ab_num;
    price = A*a_num + B*b_num + 2*C*ab_num;
    //cout<<"ab_num = "<<ab_num<<", "<<"price = "<<price<<endl;
    if(price < price_min)
      price_min = price;
  }

  cout << price_min << endl;
    
  return 0;
}
