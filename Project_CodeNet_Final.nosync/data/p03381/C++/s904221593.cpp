#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>
#include <bitset>
#include <set>

#define rep(i,n) for(long long i = 0;i<n;i++)
#define REP(i,k,n) for(long long i=k;i<n;i++)

using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int a[200200];
  int x[200200];
  rep(i,n) {
    cin >> x[i];
    a[i] = x[i];
  }
  sort(x,x+n);
  int m = n/2-1;
  rep(i,n){
    if(a[i] <= x[m]){
      cout << x[m+1] << endl;
    }else{
      cout << x[m] << endl;
    }

  }
  return 0;

}
