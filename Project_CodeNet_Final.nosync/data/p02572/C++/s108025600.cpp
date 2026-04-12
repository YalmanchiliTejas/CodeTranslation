#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
const int INF = 0x7fffffff;

using lll = long long;
using ull = unsigned long long;
using namespace std;
const ull MOD = 1000000007;

int main(){
  lll ii,jj,kk;
  vector<int> ret;
  int n;
  vector<lll> a;

  cin >> n;
  a.resize(n);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }

  lll sumAdd = 0;

  for(ii=0;ii<a.size();ii++){
    sumAdd += a[ii];
    sumAdd %= MOD;
  }
  lll sum = 0;


  
  for(ii=0;ii<a.size();ii++){
    //if(ii % 1000 == 0){
    //  cout << ii << endl;
    //}
    //for(jj=ii+1;jj<a.size();jj++){
    //  sum = a[ii] * a[jj]   + sum;
    //  sum %= MOD;
    //}

    sumAdd -= a[ii];
    if(sumAdd < 0) sumAdd += MOD;
    
    sum += a[ii] * sumAdd;
    sum %= MOD;
    
  }
  //cout << MOD << endl;
  cout << sum << endl;

  return 0;
}
