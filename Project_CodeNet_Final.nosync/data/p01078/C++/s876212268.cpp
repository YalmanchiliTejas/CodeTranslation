#include <iostream>
#include <cmath>
#include <cstdio>
#include <cassert>
#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
double ans,ko,hen,san,theta;
int n,k;
int main() {
  cin >> n >> k;
  ko = M_PI/(double)n - sin(2*M_PI/(double)n)/2;
  hen = sqrt(2-2*cos(2*M_PI/(double)n));
  theta = M_PI*((double)n-2)*((double)k-1)/((double)n)/((double)n-2);
  san = hen/2*tan(theta)*hen/2;
  ans = M_PI - ko*n - san*n;
  //cout << ko << ',' << hen << ',' << theta << ',' << san;                                                                                                                        
  //cout << ans << endl;                                                                                                                                                           
  printf("%.9f\n",ans);
  return 0;
}