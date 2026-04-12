#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>
#include <map>
#include <set>
#include <bitset>
#include <utility> 
using namespace std;

int main() {
   int N; cin >> N;
   vector<int> H(N);
   int ans=N;
   int tmpmax = 1;
   for (int i=0;i<N;i++){
       cin >> H[i];
   } 
   for (int i=0;i<N;i++){
       if (tmpmax>H[i]) {
           ans--;
       }
       else tmpmax = max(tmpmax,H[i]);
   }
   cout << ans << endl;
   return 0;
}