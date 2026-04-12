#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef unsigned int uint;
typedef long long ll;

int main(){
  int n;
  int cc = 0;
  while(cin>>n, n){
    vector<pair<int,pair<int,string> > > v(n);
    if(cc++ != 0) cout << endl;
    REP(i,n){
      int w,l,e;
      string name;
      cin>>name>>w>>l>>e;
      int point = w*3 + e;
      v[i].f = -point;
      v[i].s.f = i;
      v[i].s.s = name;
    }
    sort(v.begin(), v.end());
    REP(i,n){
      string name = v[i].s.s;
      int point = -v[i].f;
      cout << name << "," << point << endl;
    }
  }
  return 0;
}