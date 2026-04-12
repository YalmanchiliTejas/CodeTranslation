#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>

 
using namespace std;
 
#define INF 1000000000
#define EPS 1e-9
#define PI acos(-1)
 
typedef long long ll;

#define MAX_M 100

int m;
vector<ll> ans_list;

int main(){

  cin >> m;
  while(m > 0){
    m--;
    int n;
    ll money;
    ll year;
    ll ans = 0;
    cin >> money;
    cin >> year;
    cin >> n;
    while(n > 0){
      n--;
      ll mMoney = money;
      int num;
      double r;
      int mai;
      int t = 0;
      cin >> num >> r >> mai;
      if(num == 0){
	for(int i = 0; i < year; i++){
	  int B = mMoney*r/10*10;
	  t += B;
	  mMoney -= mai;
	}
	ans = max(ans, mMoney+t);
      }
      else{
	for(int i = 0; i < year; i++){
	  mMoney += -mai + mMoney*r/10*10;
	}
	ans = max(ans, mMoney);
      }
      
    }
  
    ans_list.push_back(ans);

  }

  for(int i = 0; i < ans_list.size(); i++){
    cout << ans_list[i] << endl;
  }

  return 0;

}