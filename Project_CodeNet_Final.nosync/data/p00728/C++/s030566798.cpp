#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

int main(){
   cin.tie(0);
   ios::sync_with_stdio(false);

   int n;

   while(cin >> n && n != 0){
      int a[n],sum = 0;
      rep(i,n){
         cin >> a[i];
      }
      sort(a,a+n);
      for(int i = 1; i < n - 1; ++i){
         sum += a[i];
      }
      cout << sum / (n - 2) << endl;
   }

   return 0;
}
