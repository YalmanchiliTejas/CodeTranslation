#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define sz size()
#define pb push_back
#define mp make_pair
#define ALL(X) (X).begin(),(X).end()

using namespace std;

const int INF = 1000000000;
const double eps = 1e-8;

int main(void) {
  string l = "qwertasdfgzxcvb";
  while(1){
    string s;cin>>s;
    if(s=="#")break;
    int cnt=0;
    REP(i,s.size()-1){
      bool o=l.find(s[i])==string::npos;
      bool n=l.find(s[i+1])==string::npos;
      if(o!=n)
        cnt++;
    }
    cout<<cnt<<endl;
  }
  return 0;
}