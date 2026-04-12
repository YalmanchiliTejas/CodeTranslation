#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const* argv[])
{
  int m=0,n,ans=0;
  cin >> n;
  for (int i=0;i<n;i++){
    int temp;
    cin >> temp;
    if (m<=temp)ans++;
    else continue;
    m = max(temp,m);
  }
  cout << ans<< endl;
  return 0;
}
