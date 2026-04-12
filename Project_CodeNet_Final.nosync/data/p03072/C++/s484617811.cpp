#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, t, c;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }
  c = 1;
  t = vec.at(0);
  for (int i = 1; i < n; i++) {
    if(vec.at(i) >= t){
      c++;
      t = vec.at(i);
    }
  }
  cout << c << endl;
}
    

