#include <bits/stdc++.h>
using namespace std;

int tanri(int year, int money, int tesu, double rate){
  int rishi = 0;
  int tmp = money;
  for(int i = 0; i < year; i++){
    rishi += int(tmp * rate);
    tmp -= tesu;
  }
  return tmp + rishi;
}

int hukuri_calc(int year, int money, int tesu, double rate){
  int sum = money;
  for(int i = 0; i < year; i++){
    int rishi = int(sum * rate);
    sum += rishi - tesu;
  }

  return sum;
}

int main(){
  int m = 0;
  cin >> m;
  for(int i = 0; i < m; i++){
    int money = 0;
    int year = 0;
    int kind = 0;
    int hukuri = 0;
    double rate = 0.0;
    int tesu = 0;
    cin >> money >> year >> kind;

    vector<int> ans;
    for(int j = 0; j < kind; j++){
      cin >> hukuri >> rate >> tesu;
      int tmp = 0, tmp2 = 0;
      if(hukuri == 0){
        tmp = tanri(year, money, tesu, rate);
        //cout << "tanri = " << tmp << endl;
        ans.push_back(tmp);
      } 
      else{
        tmp2 = hukuri_calc(year, money, tesu, rate);
        //cout << "hukuri = " << tmp2 << endl;
        ans.push_back(tmp2);
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans[ans.size() - 1] << endl;
    
  }
  return 0;
}