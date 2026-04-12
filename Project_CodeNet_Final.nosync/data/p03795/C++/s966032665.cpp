#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
const double PI = acos(-1.0);
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
int main(){
  int n;
  cin >> n;
  cout << n*800-(n/15)*200 << endl;  
  return 0;
}