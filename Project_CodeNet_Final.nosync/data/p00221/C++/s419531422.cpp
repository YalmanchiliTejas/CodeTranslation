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
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s; }
inline long long tonum(string s) {long long v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string tostr(T x) {ostringstream sout;sout<<x;return sout.str();}



int n, m;
string str;

int main() {
    while (cin >> n >> m) {
        if (n == 0) break;
        vint res(n);
        for (int i = 1; i <= n; ++i) res[i-1] = i;
        
        int mem = 0;
        for (int i = 1; i <= m; ++i, mem = (mem+1)%res.size()) {
            string ans = "";
            if (i % 3 == 0) ans += "Fizz";
            if (i % 5 == 0) ans += "Buzz";
            if (i % 3 != 0 && i % 5 != 0) ans = tostr(i);
            
            cin >> str;
            if (res.size() == 1) continue; 
            if (ans != str) res.erase(res.begin()+mem--);
        }
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i];
            if (i != res.size()-1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
