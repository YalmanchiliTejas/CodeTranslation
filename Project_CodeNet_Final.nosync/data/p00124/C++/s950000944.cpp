#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
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
typedef pair<int, int> PII;
static const double EPS = 1e-5;

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)

int main(void){
  int n;
  bool f = false;
  while(cin>>n){
    if(n==0) break;
    if(f)cout<<endl;
    else f=true;
    vector<pair<PII,string> > data;
    REP(i,n){
      string team;
      int win,tmp;
      cin>>team;
      cin>>tmp;
      win=tmp*3;
      cin>>tmp;
      cin>>tmp;
      win+=tmp;
      data.push_back(pair<PII,string>(PII(-win,i),team));
    }
    sort(data.begin(),data.end());
    REP(i,n){
      printf("%s,%d\n",data[i].second.c_str(),-data[i].first.first);
    }
  }


  return 0;
}