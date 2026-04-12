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

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string str; getline(cin, str);
  int ans; cin >> ans;
  
  VI num;
  for(int i=0;i<SZ(str);i+=2)
	num.PB(str[i] - '0');

  int calcM = 0;
  VI tmp = num;
  for(int i=1;i<SZ(str);i+=2)
	if(str[i] == '*'){
	  tmp[i/2+1] = tmp[i/2] * tmp[i/2+1];
	  tmp[i/2] = 0;
	}
  calcM = accumulate(ALL(tmp), 0);

  int calcL = num[0];
  for(int i=1;i<SZ(str);i+=2)
	if(str[i] == '+') calcL += num[i/2+1];
	else calcL *= num[i/2+1];

  if(calcM == calcL)
	cout << (ans == calcM? "U": "I") << endl;
  else
	cout << (ans == calcM? "M": (ans == calcL? "L": "I")) << endl;
  
  return 0;
}