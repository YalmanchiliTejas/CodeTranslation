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

int main(){
  char c;
  cin >> c;
  string v = "aeiou";
  if (v.find(c)!=-1) {
    puts("vowel");
  } else {
    puts("consonant");
  }
  return 0;
}