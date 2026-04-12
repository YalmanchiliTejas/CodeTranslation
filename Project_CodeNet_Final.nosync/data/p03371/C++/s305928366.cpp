#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;
const double PI = acos(-1.0);
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define SUM(c) accumulate((c).begin(),(c).end(),0)
#define Yn(b) puts(b?"Yes":"No")
#define YN(b) puts(b?"YES":"NO")

bool isprime(int p) {
  if (p==1) return false;
    FOR(i,2,p) {
      if (p%i==0) return false;
    }
  return true;
}

int main(){
  int a,b,c,x,y,r;
  cin >> a >> b >> c >> x >> y;
  r=0;
  if (a+b>2*c) {
    int mi = min(x,y);
    r+=mi*c*2;
    x-=mi;
    y-=mi;
  }
  if (a>c*2) {
    r+=x*c*2;
  } else {
    r+=x*a;
  }
  if (b>c*2) {
    r+=y*c*2;
  } else {
    r+=y*b;
  }
  cout << r;
  return 0;
}