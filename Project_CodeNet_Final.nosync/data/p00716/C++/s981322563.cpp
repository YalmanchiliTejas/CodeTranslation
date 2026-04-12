#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
  int m;
  cin >> m;
  for(int i=0; i<m;i++){
    int money,year,n,input;
    cin >> money;
    cin >> year;
    cin >> n;
    double s[n][3];
    int t[n];
    for(int j=0;j<n;j++){
      cin >> s[j][0] >> s[j][1] >> s[j][2];
      input = money;
      t[j] = 0;
      if(s[j][0] == 0){
        for(int l=0;l<year;l++){
          t[j] += (int)floor(input * s[j][1]);
          input -= (int)s[j][2];
        }
      }else if(s[j][0] == 1){
        for(int l=0;l<year;l++){
          input = input + (int)floor(input * s[j][1]) - (int)s[j][2];
        }
      }
      t[j] += input;
    }
    int max=0;
    for(int j=0;j<n;j++){
      if(max < t[j]){
        max = t[j];
      }
    }
    cout << max <<endl;
  }
}