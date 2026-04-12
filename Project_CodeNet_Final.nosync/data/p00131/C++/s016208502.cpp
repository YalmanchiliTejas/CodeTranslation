#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while(--n >= 0){
         vector<int> x(10);
         for(int i=0; i<10; ++i){
             int a = 1;
             for(int j=0; j<10; ++j){
                 int b;
                 cin >> b;
                 if(b)
                     x[i] |= a;
                 a <<= 1;
             }
         }

         vector<vector<int> > dp(11, vector<int>(1<<10, 0));
         for(int i=0; i<10; ++i){
             for(int j=0; j<(1<<10); ++j){
                 int tmp = x[i];
                 tmp ^= dp[i][j];
                 tmp ^= j;
                 tmp ^= (j<<1) & ((1<<10)-1);
                 tmp ^= (j>>1);
                 dp[i+1][tmp] = j;
             }
         }

         vector<int> ret(10);
         int j = 0;
         for(int i=9; i>=0; --i)
             j = ret[i] = dp[i+1][j];

         for(int i=0; i<10; ++i){
             bitset<10> bs(ret[i]);
             cout << bs[0];
             for(int j=1; j<10; ++j)
                 cout << ' ' << bs[j];
             cout << endl;
         }
    }
}