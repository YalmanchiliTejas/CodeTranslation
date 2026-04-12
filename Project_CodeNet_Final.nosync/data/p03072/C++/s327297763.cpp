#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()

int main() {
   int n;
   cin >> n;
   int ans=0,h,hmax=-1;
   rep(i,n){
      cin >> h;
      if(h>=hmax)
      ans++;
      hmax=max(h,hmax);
   }
   cout << ans << endl;
}