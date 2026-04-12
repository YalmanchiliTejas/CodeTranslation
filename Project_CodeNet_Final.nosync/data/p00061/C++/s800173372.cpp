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
#include <fstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int m,n;
  map<int,int> date;
  map<int,int> juni;
  set<int> num;
  while(scanf("%d,%d",&m,&n)){
    if(m==0&&n==0) break;
    date[m]=n;
    num.insert(n);
  }
  int c=1;
  for(int i=30;i>=0;i--){
    if(num.find(i)!=num.end()){
      juni[i] = c++;
    }
  }
  int a;
  while(cin>>a){
    cout<<juni[date[a]]<<endl;
  }
  return 0;
}