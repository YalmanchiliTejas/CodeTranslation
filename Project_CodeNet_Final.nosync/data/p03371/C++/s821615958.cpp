#include<bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(i=0;i<n;i++)
#define test(a) cout << "*" << a << endl
#define ll long long
int main(){
  int money[2];
  int moneyAB;
  int num[2];
  int numKyoutuu;
  int sum=0;
  int i;
  
  cin >> money[0] >> money[1];
  cin >> moneyAB;
  moneyAB *= 2;
  cin >> num[0] >> num[1];  
  //test(moneyAB);
  
  sum = min(money[0]+money[1],moneyAB) * min(num[0],num[1]);
  
  numKyoutuu = min(num[0],num[1]);
  num[0] -= numKyoutuu;
  num[1] -= numKyoutuu;
  
  if(num[0]>num[1])
    i = 0;  
  else
    i = 1;
  
  sum += num[i] * min(money[i],moneyAB);
    
  cout << sum << endl;
  
  //test(numA);
  //test(numB);

}