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
#include <cassert>

using namespace std;
typedef long long ll;

int main()
{
   ll N, X, M;
   cin >> N >> X >> M;
   vector<ll> val(M + 1);
   vector<ll> sum(M + 1);
   vector<ll> ind(M, -1);
   sum[0] = 0;
   sum[1] = X;
   val[0] = X;
   ind[X] = 0;
   int loopStart = -1;
   int loopEnd = -1;
   for (int i = 1; i < M + 1; i++)
   {
      val[i] = (val[i - 1] * val[i - 1]) % M;
      //cout << i << "," << val[i] << endl;
      sum[i + 1] = sum[i] + val[i];
      if (ind[val[i]] != -1)
      {
         loopStart = ind[val[i]];
         loopEnd = i;
         break;
      }
      else
      {
         ind[val[i]] = i;
      }
   }
   if (N - 1 <= loopEnd)
   {
      cout << sum[N] << endl;
      return 0;
   }
   else
   {
      long long ans = sum[loopEnd];
      long long loopSum = sum[loopEnd] - sum[loopStart];
      long long loopLen = loopEnd - loopStart;
      long long time = (N - loopEnd) / loopLen;
      ans += time * loopSum;
      long long rest = (N - loopEnd) % loopLen;
      ans += sum[loopStart + rest] - sum[loopStart];
      cout << ans << endl;
   }
   return 0;
}
