#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  char c;
  cin>>c;
  if((c-'a')*(c-'i')*(c-'u')*(c-'e')*(c-'o')==0)cout<<"vowel"<<endl;
  else cout<<"consonant"<<endl;
  return 0;
}
