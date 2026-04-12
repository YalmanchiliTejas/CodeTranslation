#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <numeric>
#include <set>
#include <unordered_set>
#include <queue>
#include <boost/math/constants/constants.hpp>
#include <boost/math/common_factor_rt.hpp>

using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0;i < n;i++)
#define FOR(i, n, m) for(int i=n; i<m; ++i)

int main() {
  string S;
  cin >> S;
  ll sum=0;
  rep(i,3){
    if(S[i]=='A') sum+=1;
  }
  
  if(sum==1 || sum==2){
	cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}