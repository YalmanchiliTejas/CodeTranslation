#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int bemiho,katoshi,kosakana = 0;
  cin >> bemiho >> katoshi >> kosakana;
  int nibuchan = 0;
  nibuchan = 10*katoshi + kosakana;
  if(nibuchan % 4 == 0){
    cout << "YES" << endl;
  }
  else{ 
    cout << "NO" << endl;
  }
}