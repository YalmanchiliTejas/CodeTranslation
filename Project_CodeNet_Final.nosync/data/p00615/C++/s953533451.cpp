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

#define REP(i,n) for(long long i=0;i<n;++i)
#define REPR(i,n) for(long long i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define SUR 1000000007
#define pb push_back
#define pf push_front
#define MP make_pair
#define SV(v) {for(long long sitr=0;sitr<v.size();++sitr){cin>>v[sitr];}}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

int main(){

  while(true){
    int n, m;
    scanf("%d %d", &n, &m);
    if(n == 0 && m == 0){
      break;
    }

    vector<int> a;
    int tmp;
    REP(i,n){
      scanf("%d", &tmp);
      a.pb(tmp);
    }

    REP(i,m){
      scanf("%d", &tmp);
      a.pb(tmp);
    }

     if(n + m == 1){
      printf("%d\n", a[0]);
      continue;
    }

    SORTV(a);
    int ans = a[0];
    REP(i,m+n-1){
      ans = max(ans, a[i+1] - a[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}


