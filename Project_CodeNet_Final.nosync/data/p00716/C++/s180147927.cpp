#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int m;
  scanf("%d", &m);
  while(m--){
    unsigned int startMoney, maxMoney = 0;
    int year, n;
    scanf("%u", &startMoney);
    scanf("%d", &year);
    scanf("%d", &n);
    while(n--){
      int compound, fee;
      unsigned int money = startMoney, addMoney = 0;
      double rate;
      scanf("%d %lf %d", &compound, &rate, &fee);
      for(int i = 0; i < year; i++){
        if(compound){
          money += money * rate;
          money -= fee;
        }
        else{
          addMoney += money * rate;
          money -= fee;
        }
      }
      maxMoney = max(maxMoney, money + addMoney);
    }
    printf("%u\n", maxMoney);
  }
  return 0;
}