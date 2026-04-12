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



template<class T> struct Parser {
    typedef pair<T,int> parsed;
    
    // rewrite if we need (the following is int version)
    static T conv(string str) {
        T res = 0;
        for (int i = 0; i < str.size(); ++i) {
            res = res * 10 + (str[i] - '0');
        }
        return res;
    }
    
    static T solve(string str) {
        return equation(str).first;
    }
    
    static parsed equation(string str, int p = 0) {
        parsed res = factor(str, p);
        while (str[res.second] == '+' || str[res.second] == '-') {
            parsed temp = factor(str, res.second+1);
            if (str[res.second] == '+') res.first = res.first + temp.first;
            else if (str[res.second] == '-') res.first = res.first - temp.first;
            res.second = temp.second;
        }
        return res;
    }
    
    static parsed factor(string str, int p = 0) {
        parsed res = term(str, p);
        while (str[res.second] == '*' || str[res.second] == '/') {
            parsed temp = term(str, res.second+1);    
            if (str[res.second] == '*') res.first = res.first * temp.first;
            else if (str[res.second] == '/') res.first = res.first / temp.first;
            res.second = temp.second;
        }
        return res;
    }
    
    static parsed term(string str, int p = 0) {
        if (str[p] == '(') {
            parsed res = equation(str, p+1);
            res.second += 1;
            return res;
        }
        else {
            string snum = "";
            if (p < str.size()) {
                while (isdigit(str[p]) || str[p] == 'i') {
                    snum += str[p++];
                }
            }
            T num = conv(snum);
            return parsed(num, p);
        }
    }
};

string str;
long long ans;

int main() {
    //freopen( "/Users/macuser/Dropbox/Contest/input.in", "r", stdin );
    while (cin >> str >> ans) {
        long long mres = Parser<long long>::solve(str);
        long long lres = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '+' || str[i] == '*') {
                str = str.substr(0, i) + " " + str[i] + " " + str.substr(i+1);
                ++i;
            }
        }
        //COUT(str); 
        
        long long num;
        char c;
        istringstream sin(str);
        sin >> lres;
        while (sin >> c >> num) {
            if (c == '+') lres += num;
            if (c == '*') lres *= num;
        }
        
        //COUT(mres); COUT(lres);
        
        if (mres == ans && lres != ans) puts("M");
        else if (mres != ans && lres == ans) puts("L");
        else if (mres == ans && lres == ans) puts("U");
        else if (mres != ans && lres != ans) puts("I");
    }
    return 0;
}
