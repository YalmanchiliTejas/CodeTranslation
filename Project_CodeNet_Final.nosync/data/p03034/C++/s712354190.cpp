#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>

using namespace std;

int main(){
   int N;
   cin >> N;
   long long s[N];
   for(int i=0; i<N; i++){
      cin >> s[i];
   }
   long long ans = 0;
   for(int i=1;i<N; i++){
      long long tmp = 0;
      for(int k=1; k*i < N && i < N-1-k*i; k++){
         if((N-1-k*i)%i ==0 && (N-1-k*i)/i <=k) break;
         tmp += s[k*i];
         tmp += s[N-1-k*i];
         ans = max(ans,tmp);
      }
   }
   cout << ans << endl;

   return 0;
}
