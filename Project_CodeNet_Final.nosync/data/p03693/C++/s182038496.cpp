#include<bits/stdc++.h>
using namespace std;

int main(){
  int r, g, b;
  cin >> r >> g >>b;

  int ans4 = 100 * r + 10 * g + b;

  if(ans4 % 4 ==0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
