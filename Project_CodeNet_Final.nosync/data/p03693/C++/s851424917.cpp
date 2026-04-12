#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  ll a,b,c;
  cin >> a >> b >> c;
  ll k = a*100+b*10+c;
  // cout << k;
  if(k%4==0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
