#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = pow(10,9)+7;

int main()
{
  int n;
  cin >> n;
  int h;
  cin >> h;
  int cnt=1,tmp=h;
  for(int i=1; i<n; i++)
  {
    cin >> h;
    if(h>=tmp){
      cnt++;
      tmp = h;
    }
  }
  cout << cnt << endl;
  return 0;
}
