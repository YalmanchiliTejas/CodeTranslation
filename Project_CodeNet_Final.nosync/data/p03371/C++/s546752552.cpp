#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;
int main(){
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int min = INT_MAX;
  int max_mix = max(X, Y)*2;
  for(int i = 0; i <= max_mix; i+=2){
    int a_p = 0, b_p = 0;
    if(X-i/2 >= 0) a_p = X-i/2;
    if(Y-i/2 >= 0) b_p = Y-i/2;
    int price = A * a_p + B * b_p + C * i;
    if( price < min ) min = price;
  }

  cout << min << endl;
}
