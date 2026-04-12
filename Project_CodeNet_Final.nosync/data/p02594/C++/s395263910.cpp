#pragma region Macros
// ===========
// include
// ===========
#include <bits/stdc++.h>

using namespace std;

// ===========
// typedef
// ===========
typedef int64_t int64;
typedef vector<int64> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;

// ===========
// conversion
// ===========
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

// ===========
// math
// ===========
template<class T> inline T sqr( T x ){ return x * x; }
inline int64 Factorial( int64 n ){ return n == 0 ? 0 : ( n == 1 ? 1 : Factorial( n - 1) * n  ); }

// ===========
// repetition
// ===========
#define rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a), __length = int(b); i < __length; ++i)

void input(vector<int64> *vec, const int size){ vec->resize(size); rep(i, size) { cin >> vec->at(i); } }
void input(vector<string> *vec, const int size){ vec->resize(size); rep(i, size) { cin >> vec->at(i); } }

#pragma endregion //Macros

int main()
{
    int X;
    cin >> X;
    if( X >= 30 )
    {
        cout << "Yes" << endl;
    } else 
    {
        cout << "No" << endl;
    }
    return 0;
}
