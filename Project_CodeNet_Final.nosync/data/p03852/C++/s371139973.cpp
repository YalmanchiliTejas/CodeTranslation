#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

#define MAX(x,y) ( (x) > (y) ? (x) : (y) )
#define MIN(x, y) ( (x) < (y) ? (x) : (y) )
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)
#define IVFOR(p,a) for(vector<int>::iterator p = (a).begin(); p!=(a).end(); p++)
#define ILFOR(p,a) for(list<int>::iterator p = (a).begin(); p!=(a).end(); p++)
#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define CHECK(x)  cout << #x << " = " << (x) << endl
#define FINA(y) cout << (y) << endl

int main(){

  char c;
  cin >> c;
  
  if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
    FINA("vowel");
  else
    FINA("consonant");

 return 0;
}
