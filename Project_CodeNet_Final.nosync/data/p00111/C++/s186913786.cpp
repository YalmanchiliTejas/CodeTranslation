#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef pair<int,int> pint;
typedef pair<long long, long long> pll;

#define MP make_pair
#define PB push_back
#define ALL(s) (s).begin(),(s).end()
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P) 
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P) 
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P) 
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s; }
inline long long tonum(string s) {long long v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string tostr(T x) {ostringstream sout;sout<<x;return sout.str();}

string IN[32] = { "101", "000000", "000011", "10010001", "010001", "000001", 
    "100101", "10011010", "0101", "0001", "110", "01001", "10011011", "010000", "0111", "10011000", "0110", "00100",
    "10011001", "10011110", "00101", "111", "10011111", "1000", "00110", "00111", "10011100", "10011101", 
    "000010", "10010010", "10010011", "10010000"};


map<char,string> ma;
map<string,char> ma2;

string str;

int main() {
    for (int i = 0; i < 26; ++i) {
        string tmp = "";
        for (int j = 4; j >= 0; --j) {
            if (i & (1<<j)) tmp += "1";
            else tmp += "0";
        }
        ma[ 'A'+i ] = tmp;
    }
    ma[' '] = "11010"; ma['.'] = "11011"; ma[','] = "11100";ma['-'] = "11101"; ma[39] = "11110"; ma['?'] = "11111";
    ma2[IN[0]] = ' '; ma2[IN[1]] = 39; ma2[IN[2]] = ','; ma2[IN[3]] = '-'; ma2[IN[4]] = '.'; ma2[IN[5]] = '?';
    for (int i = 0; i < 26; ++i) {
        ma2[IN[i+6]] = 'A'+i;
    }
    
    while (getline(cin, str)) {
        string tmp = "";
        for (int i = 0; i < str.size(); ++i) tmp += ma[str[i]];
        string res = "";
        int t = 0;
        string sstr = "";
        for (t = 0; t < tmp.size(); ++t) {
            sstr += tmp[t];
            if (ma2.count(sstr)) {
                res += ma2[sstr];
                sstr = "";
            }
        }
        cout << res << endl;
    }
    return 0;
}
