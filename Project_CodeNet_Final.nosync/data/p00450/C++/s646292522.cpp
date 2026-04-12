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



int n;
int b;

int main() {
    while (cin >> n) {
        if (n == 0) break;
        
        vint seg[2]; 
        int pre = -1;
        for (int i = 0; i < 2; ++i) {seg[i].clear(); seg[i].PB(-1);}
        for (int i = 0; i < n; ++i) {
            cin >> b;
            if (i & 1) {
                if (pre == b) seg[b].back()++;
                else {
                    if (!seg[0].empty()) seg[0].pop_back(); 
                    if (!seg[1].empty()) seg[1].pop_back();
                    seg[b].PB(i);
                }
            }
            else {
                if (pre == b) seg[b].back()++;
                else seg[b].PB(i);
            }
            pre = b;
            
            //COUT(i); COUT(seg[0]); COUT(seg[1]); cout << endl;
        }
        int res = 0;
        bool zs = true;
        if (seg[0][0] == -1) seg[0].erase(seg[0].begin());
        if (seg[1][0] == -1) seg[1].erase(seg[1].begin());
        
        if (seg[0].size() == 0) zs = false;
        else if (seg[1].size() > 0) if (seg[0][0] > seg[1][0]) zs = false;
        
        vint vec;
        if (zs) vec.PB(-1);
        for (int i = 0; i < seg[0].size(); ++i) vec.PB(seg[0][i]);
        for (int i = 0; i < seg[1].size(); ++i) vec.PB(seg[1][i]);
        sort(ALL(vec));
        
        //COUT(vec);
        
        for (int i = 0; i+1 < vec.size(); i += 2) res += vec[i+1] - vec[i];
        
        cout << res << endl;
    }
    return 0;
}
