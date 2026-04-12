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



#define roll_swap(x, a, b, c, d) swap(x.a, x.b), swap(x.b, x.c), swap(x.c, x.d);
template<class T> struct Dice {
    T top, front, right, left, back, bottom;
    
    Dice(T to = 1, T fr = 2, T ri = 3, T le = 4, T ba = 5, T bo = 6) 
        : top(to), front(fr), right(ri), left(le), back(ba), bottom(bo) { }
    void roll_right() { roll_swap((*this), top, left, bottom, right); }
    void roll_left() { roll_swap((*this), top, right, bottom, left); }
    void roll_front() { roll_swap((*this), top, back, bottom, front); }
    void roll_back() { roll_swap((*this), top, front, bottom, back); }
    void roll_cw() { roll_swap((*this), back, left, front, right); }
    void roll_ccw() { roll_swap((*this), back, right, front, left); }
    
    vector<Dice<T> > all_rotate() {
        vector<Dice> res(24);
        Dice<T> d;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 4; j++) {
                res[i * 4 + j] = d;
                d.roll_cw();
            }
            if (i & 1) d.roll_front();
            else d.roll_right();
        }
        return res;    
    }
};
    

int n;
string str;

int main() {
    while (cin >> n) {
        if (n == 0) break;
    
        int res = 1;
        Dice<int> d;
        
        for (int i = 0; i < n; ++i) {
            cin >> str;
            if (str == "North") d.roll_back();
            else if (str == "East") d.roll_right();
            else if (str == "South") d.roll_front();
            else if (str == "West") d.roll_left();
            else if (str == "Right") d.roll_cw();
            else d.roll_ccw();
            
            res += d.top;
        }
        
        cout << res << endl;
    }
    return 0;
}
