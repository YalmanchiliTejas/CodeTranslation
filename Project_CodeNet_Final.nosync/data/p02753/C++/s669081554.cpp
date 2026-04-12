//Coalbert Ramirez
//AtCoder Begginer Contest A - Station and Bus
#include <bits/stdc++.h>
using namespace std;

int main(){
  char station[3];
  cin >> station[0] >> station[1] >> station[2];
  cout << ((station[0]!=station[1] || station[0]!=station[2])? "Yes\n": "No\n");
  return 0;
}