#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(intl i=0;i<(intl)(n);i++)
#define Rep1(i,n) for(intl i=1;i<(intl)(n)+1;i++)
#define vec vector
#define fi first
#define se second
#define SortA(v) sort(v.begin(), v.end())
#define SortD(v) sort(v.rbegin(), v.rend())
#define All(a) (a).begin(),(a).end()
#define INF 9223372036854775807;
using intl = int64_t;
using vi = vec<intl>;
using vvi = vec<vi>;
vec<intl> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vec<intl> dy = {1, 0, -1, 0, 1, -1, 1, -1};



int main(){
  intl A,B,AB,X,Y;
  cin >> A>>B>>AB>>X>>Y;
  intl mincost=INF;
  Rep(i, max(X,Y)+1 ){
    intl cost = AB*2*i + A*max(X-i,(intl)(0)) + B*max(Y-i,(intl)(0));
    mincost= min (mincost,cost);
  }
  cout <<mincost;
}

  