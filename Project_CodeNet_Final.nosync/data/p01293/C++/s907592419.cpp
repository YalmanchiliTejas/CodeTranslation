//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int f(char c){
  if(c == 'A') return 14;
  if(c == 'K') return 13;
  if(c == 'Q') return 12;
  if(c == 'J') return 11;
  if(c == 'T') return 10;
  return c - '0';
}

bool gt(int n1, char c1, int n2, char c2, char trump, char lead){
  if(c1 == c2) return n1 > n2;
  if(c1 == trump) return true;
  if(c2 == trump) return false;
  if(c1 == lead) return true;
  if(c2 == lead) return false;
  return n1 > n2;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  char ch;
  while(cin>>ch,ch!='#'){
	char in[2];
	VI num[4];
	string suit[4];
	REP(i,4) REP(j,13){
	  cin >> in;
	  num[i].PB(f(in[0]));
	  suit[i].PB(in[1]);
	}

	int ns = 0, ew = 0;
	int led = 1;
	REP(i,13){
	  int i1, i2;
	  char led_ch = suit[led][i];
	  if(gt(num[0][i], suit[0][i], num[2][i], suit[2][i], ch, led_ch))	i1 = 0;
	  else i1 = 2;
	  if(gt(num[1][i], suit[1][i], num[3][i], suit[3][i], ch, led_ch))	i2 = 1;
	  else i2 = 3;

	  if(gt(num[i1][i], suit[i1][i], num[i2][i], suit[i2][i], ch, led_ch))
		++ns, led = i1;
	  else
		++ew, led = i2;
	}
	if(ns > ew) cout << "NS " << ns-6 << endl;
	else cout << "EW " << ew-6 << endl;
  }
  
  return 0;
}