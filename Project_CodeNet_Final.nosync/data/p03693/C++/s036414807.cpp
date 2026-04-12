#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;

int main()
{
  int r,g,b;
  cin >> r>>g>>b;

  int num = r*100+g*10+b;

  if(num%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}