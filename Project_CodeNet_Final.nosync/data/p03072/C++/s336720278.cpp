#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<cmath>
#include<iomanip>

using namespace std;

typedef long long ll;

int main()
{
  int n; cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {cin >> h[i];}

  int ans = 1;
  for (int i = 1; i < n; i++){
    bool is_ok = true;
    for (int j = 0; j < i; j++)
    {
      if(h[i] < h[j]) {
        is_ok = false;
        break;
      }
    }
    if(is_ok == true) ans++;
  }

  cout << ans << endl;
  return 0;
  
}
