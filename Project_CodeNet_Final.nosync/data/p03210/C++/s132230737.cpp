#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define ALL(x) x.begin(),x.end()
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

typedef long long ll;
bool LTE(double a,double b) { return equals(a,b) || a < b; }
bool LT(double a,double b) { return !equals(a,b) && a < b; }

void compute() {

}
// A
int main() {

  int x;
  cin >> x;
  if( x ==5 || x ==7 || x ==3 ) puts("YES")  ;
  else puts("NO");
  compute();
  return 0;
}
