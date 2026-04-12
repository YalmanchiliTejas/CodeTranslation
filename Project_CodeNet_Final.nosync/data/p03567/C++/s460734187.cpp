#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<long long> vlong;
#define vpush(a,x) a.push_back(x);
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define INF 2e9
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  int flag=0;
  int si=s.size();
  rep(i,si){
    if(s[i]=='A'){
      if(s[i+1]=='C'){
	flag=1;
      }
    }
  }
  if(flag==1){
    cout<<"Yes"<<'\n';
  }
  else{
    cout<<"No"<<'\n';
  }
  return(0);
}
  
