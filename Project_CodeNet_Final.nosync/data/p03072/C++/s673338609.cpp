#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,ma,count = 1;
  int h[105];
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> h[i];
  }
  ma = h[0];
  for(int i=1; i<n; i++){
    if(ma <= h[i]) count++;
    ma = max(ma,h[i]);
  }
  cout << count << endl;
  return 0;
}
