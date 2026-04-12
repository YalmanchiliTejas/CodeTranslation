#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int x,y,z;
  cin >> x >> y >> z;
  bool flag = true;
  int i = 1;
  while(flag){
    int l = y*i + z*(i+1);
    if(l <= x) i++;
    else {
      i--;
      flag = false;
    }
  }
  cout << i << endl;
}
