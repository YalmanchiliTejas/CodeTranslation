
#define TESTING

// INCLUDE
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;

// types
typedef long long            int64 ;
typedef unsigned long long   uint64 ;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef int64 hash_type;

// Shortcuts
#define all(_xx)             _xx.begin(), _xx.end()
#define pb                   push_back
#define SS                   stringstream
#define mp(XX, YY)           make_pair(XX, YY)
#define fi                   first
#define se                   second

#define pii                  pair<int, int>
#define pcc                  pair<char, char>
#define pucc                 pair<uchar, uchar>
#define pll                  pair<long long, long long>
#define pdd                  pair<double, double>

#define vl                   vector<long long>
#define vs                   vector<string>
#define vd                   vector<double>
#define vc                   vector<char>
#define vi                   vector<int>
#define vvc                  vector<vector<char>>
#define vvi                  vector<vector<int>>
#define vvl                  vector<vector<long long>>
#define vpcc                 vector<pair<char,char> >
#define vpdd                 vector<pair<double,double> >
#define vpii                 vector<pair<int,int>> 
#define vpll                 vector<pair<long long,long long>> 

#define re(II, NN)           for (int II(0), _NN(NN); (II) < (_NN); ++(II))
#define fod(II, XX, YY)      for (int II(XX), _YY(YY); (II) >= (_YY); --(II))
#define fo(II, XX, YY)       for (int II(XX), _YY(YY); (II) <= (_YY); ++(II))

template <class T> int size (const T& value) {return value.size();}

// ostream operator for STL types: pair, vector, vector<vector>, set, unordered_set, map, unordered_map
template <class T>
std::ostream& PrintContainer (std::ostream& stream, const T& container) {
    for (auto el : container) stream << el << " "; return stream;
}

template<class T> std::ostream&  operator <<(std::ostream& stream, const set<T> & s) {
    return PrintContainer (stream, s);
}

template<class T> std::ostream&  operator <<(std::ostream& stream, const unordered_set<T> & s) {
    return PrintContainer (stream, s);
}

template<class T> std::ostream&  operator << (std::ostream& stream, const vector<T> & v) {
    return PrintContainer (stream, v);
}

template<class T, class V> std::ostream&  operator << (std::ostream& stream, const map<T, V> & m) {
    return PrintContainer (stream, m);
}

template<class T, class V> std::ostream&  operator << (std::ostream& stream, const unordered_map<T, V> & m) {
    return PrintContainer (stream, m);
}

template<class T, class V> std::ostream&  operator << (std::ostream& stream, const pair<T, V> & p) {
    stream << p.first << "," << p.second << " ";
    return stream;
}

template<class T> std::ostream&  operator <<(std::ostream& stream, const vector<vector<T> > & v) {
    for (auto line : v) { for (auto el : line) stream << el << " "; stream << "\n";}
    return stream;
}
// End ostream

// Variable debug, enabled with TESTING
#ifdef TESTING
// Adapted from http://codeforces.com/blog/entry/15643
vector<string> debug_split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);}

void debug_err() {cerr << "\n";}
template<typename T, typename... Args>
void debug_err(vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << " | ";
    debug_err(++it, args...);
}

class Debugger {
public:
    template <class T> void Output (const T& v) {cerr << v << " ";}
    template <class T> Debugger& operator , (const T& v) {Output(v);return *this;}
} dbg;

#define trace(args...) { vector<string> _v = debug_split(#args, ','); debug_err(_v.begin(), args); }
#define warn(args...) {dbg,args; cerr << "\n"; cerr.flush();}
#define echo(arg) {cerr << #arg << ": "; dbg,arg; cerr << "\n"; cerr.flush();}
#else
#define warn(args...) {}
#define echo(arg) {}
#define trace(args..) {}
#endif
// End debug

// Helper
template <typename U, typename V>
void remin (U& A, V B) {
    if (A > B) A = B;
}

template <typename U, typename V>
void remax (U& A, V B) {
    if (A < B) A = B;
}
//---- End of template code -----//

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int nr = 100 * r + 10 * g + b;

    cout << (nr % 4 == 0 ? "YES\n" : "NO\n");

    return 0;
}
