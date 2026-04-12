#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define SUR 1000000007
#define pb push_back
#define pf push_front
#define MP make_pair

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

bool seikai[100];

int main(){

  vector<int> s, s2;
  while(true){
    int a, b;
    scanf("%d,%d", &a, &b);
    if(a == 0 && b == 0) break;
    s.pb(b);

    if(!seikai[b]){
      s2.pb(b);
      seikai[b] = true;
    }
  }

  sort(ALL(s2), greater<int>());
  
 
  int len = s2.size();
  int q;
  while(scanf("%d", &q) != EOF){
    int score = s[q-1];
    REP(i,len){
      if(s2[i] == score){
        //cout << s2[i] << endl;
        printf("%d\n", i+1);
        break;
      }
    }
  }
  return 0;
}


