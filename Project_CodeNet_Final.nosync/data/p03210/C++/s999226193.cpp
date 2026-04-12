#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 100100100;
using namespace std;

int main()
{
  int X;
  bool res=false;
  cin >> X;

  if(X==7||X==5||X==3) res=true;

  if(res) cout << "YES" << endl;
  else cout << "NO" << endl;
}