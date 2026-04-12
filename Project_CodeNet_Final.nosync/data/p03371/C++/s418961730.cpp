#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  long long int a_price, b_price, ab_price, a_num, b_num;
  cin >> a_price >> b_price >> ab_price >> a_num >> b_num;
  if(a_price + b_price <= ab_price * 2){
    cout << a_price * a_num + b_price * b_num << endl;
    return 0;
  }
  if(a_num < b_num) {
    int swap;
    swap = a_price;
    a_price = b_price;
    b_price = swap;
    swap = a_num;
    a_num = b_num;
    b_num = swap;
  }
  long long  int price = b_num * ab_price * 2;
  a_num -= b_num;
  price += min(a_price*a_num, ab_price*a_num*2);
  //a_price * a_num
  cout << price << endl;
  return 0;
}
