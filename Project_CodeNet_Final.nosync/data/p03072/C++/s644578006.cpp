#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int GCD(const int& a, const int& b){
   const int& _a = max(a,b);
   const int& _b = min(a,b);
   if(_a % _b == 0){
      return _b;
   }
   else{
      return GCD(_b, _a % _b);
   }
}

int LCM(const int& a, const int& b){
   const int& _a = max(a,b);
   const int& _b = min(a,b);
   return (_a*_b)/(GCD(_a, _b));
}

int main(){
   int n;
   cin >> n;
   vector<int> h(n);
   for(int i = 0; i < n; i++){
      cin >> h[i];
   }

   // ポイントは単純にi,jを全探索するのではなく, jの終了条件j < iとして探索.
   // can_view = trueとして, 見えない山が出現した時点でfalseにしてbreakする.
   // あるiの条件に対するすべてのjに対してtrueだった場合のみans++とする.
   int ans = 0;
   for(int i = 0; i < h.size(); i++){
      bool can_view = true;
      for(int j = 0; j < i; j++){
         if(h[j] > h[i]){
            can_view = false;
            break;
         }
      }
      if(can_view){
         ans++;
      }
   }

   cout << ans << endl;

   return 0;
}