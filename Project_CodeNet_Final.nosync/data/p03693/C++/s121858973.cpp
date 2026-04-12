#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
const double PI = acos(-1.0);
const string ALP = "abcdefghijklmnopqrstuvwxyz";
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
int main(){
  int r,g,b;
  cin >> r >> g >> b;
  cout << ((g*10+b)%4==0?"YES":"NO") << endl;
  return 0;
}