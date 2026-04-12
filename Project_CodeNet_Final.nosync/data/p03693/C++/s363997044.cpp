#include <bits/stdc++.h>
using namespace std;


int main()
{
  int r,g,b;
  cin >> r >> g >> b;

  int ret = 100 * r + 10 * g + b;
  if(ret % 4 == 0){
    cout << "YES" << endl;
  }else if(ret % 4 != 0){
    cout << "NO" << endl;
  }
}
