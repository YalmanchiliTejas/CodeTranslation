#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const* argv[])
{
  int n, ans=0;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h.at(i);
  }
  int tmpmax = h[0];
  for (int i = 0; i < n; i++) {
    if( i == 0 ) ans++;
    else{
        if( tmpmax <= h[i]){
            ans++;
            tmpmax = h[i];
        }
    }
  }
  cout << ans << endl;
  return 0;
}
