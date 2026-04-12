#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int a,b,c;
  cin >> a >> b >> c;
  int sum = a*100 + b*10 + c;
  if(sum%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
