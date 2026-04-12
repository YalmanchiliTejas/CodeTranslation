#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define LOOP(i, v) for(int i = 0; i < v.size(); i++)
#define EPS 1e-9
#define INF 1e12
#define debug(x) cerr << "DEBUG : " << (#x) << " => " << (x) << endl

int main()
{
  int N;
  vi a;
  vi b;
  
  scanf("%d", &N);
  a.resize(N);
  b.resize(N);
  REP(i, 0, N-1)
  {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  
  sort(b.begin(), b.end());
  
  int d = b[(N/2)-1];
  int e = b[N/2];
  
  REP(i, 0, N-1)
  {
    if(a[i] >= e) printf("%d\n", d);
    else printf("%d\n", e);
  }
    
  return 0;
}