#include <bits/stdc++.h>
using namespace std;

int main(){
  int N100,N10,N1;
  cin >> N100 >> N10 >> N1;
  const int N= N100*100+ N10*10+ N1;

  string ans= (N%4==0) ? "YES" : "NO";

  cout << ans << endl;
}