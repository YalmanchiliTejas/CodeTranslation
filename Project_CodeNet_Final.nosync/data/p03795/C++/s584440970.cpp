#include<bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  
  cout << n * 800 - int(n/15) * 200 << endl;
  return 0;
}