//#include <bits/stdc++.h>
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
#include <bitset>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef long long LL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const LL MOD = 1e9+7; 
//vector <vector<int>> x(20, vector<int> (20)), y(20,vector<int> (20));
/*int counter_1 (int x) {
    if(x == 0) return 0;
    return counter_1(x >> 1) + (x & 1);
}*/

int main() {
string s, tmp;
map<char, int> count, ans;
int n;
cin >> n;
for(char i = 'a'; i<='z'; i++){
  ans[i] = 52;
}
REP(i, n){
  cin >> s;
  int l = s.size();
  char f='a';
  for(char j = 'a'; j<='z'; j++){
  count[j] = 0;
  }
  REP(j, l){
    count[s[j]]++;
    if(f<s[j]) f=s[j];
  }

  for(char j = 'a'; j<='z'; j++){
    ans[j]=min(ans[j], count[j]);
  }
//  cout << f << endl;

}
/*for(char i = 'a'; i<='z'; i++){
  cout << i << ' ' <<  ans[i] << ' ' << count[i] << ' ' << endl;
}*/
for(char i = 'a'; i<='z'; i++){
  REP(j,ans[i]) cout << i;
}
cout << endl;

}