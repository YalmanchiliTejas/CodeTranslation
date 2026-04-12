#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct PLAN{
  int type;
  double par;
  int cost;
};

PLAN plan[101];
int kinds,year,n,startMoney;
void solve(){
  long maxMoney = -1;

  for(int i = 0; i < kinds; i++){
    long money = startMoney;
    long rishi = 0;
    for(int j = 0; j < year; j++){
      if(plan[i].type == 0){//単利
        rishi += plan[i].par * money;
        money -= plan[i].cost;
      }
      else{//複利
        money += plan[i].par * money;
        money -= plan[i].cost;
      }
    }
    if(plan[i].type == 0) maxMoney = max(maxMoney, money + rishi);
    else maxMoney = max(maxMoney,money);
  }
  cout << maxMoney << endl;
  return ;
}



int main(){
  cin >> n;
  for(int input = 0 ; input < n; input ++){
    cin >> startMoney;
    cin >> year;
    cin >> kinds;
    for(int i = 0; i < kinds; i++){
      cin >> plan[i].type >> plan[i].par >> plan[i].cost;
    }
    solve();
  }
  return 0;
}

