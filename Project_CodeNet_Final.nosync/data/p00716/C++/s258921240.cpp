#include <iostream>

using namespace std;
typedef unsigned long long int yen;

int main(){
  int year, n, m, kind, fee;
  double percent;
  yen benefit;
  yen fund;
  yen res;
  yen max_benefit;
  cin >> m;
  for(int i=0;i < m;i++){
    cin >> fund >> year >> n;
    max_benefit = 0;
    for(int j=0;j < n;j++){
      cin >> kind >> percent >> fee;
      res = fund;
      benefit = 0;
      for(int k=0;k < year;k++){
        if(kind){
          res += percent * res - fee;
        }else{
          benefit += percent * res;
          res -= fee;
        }
      }
      max_benefit = max( res + benefit, max_benefit);
    }
    cout << max_benefit << endl;
  }
  return 0;
}