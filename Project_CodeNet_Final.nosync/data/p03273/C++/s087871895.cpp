#include <bits/stdc++.h>
using namespace std;
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
typedef pair<string, int> PSI;

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
#define SORTG(c) sort((c).begin(),(c).end(),greater<auto>())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define REP(i,n)  for(int i=0; i<(n); i++)

//constant
//--------------------------------------------
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const LL MOD = 1e9+7; 
int main(){
  int n, cnt=0;
  int h, w, h1, w1;
  cin >> h >> w;
  h1=h;
  w1=w;
  vector<vector<char>> s(h,vector<char>(w));
  REP(i, h){
      REP(j,w){
          cin >> s[i][j];
        }
    }
    vector<bool> tt(h, false), yk(w, false);
    REP(i, h){
      REP(j,w){
          if(s[i][j]=='#'){
              tt[i]=true;
              yk[j]=true;
            }
        }
    } 
    REP(i, h){
        if(tt[i]){
            REP(j,w){
                if(yk[j]){
                    cout << s[i][j];
                }
            }
            cout << endl;
        }
    } 
     
}