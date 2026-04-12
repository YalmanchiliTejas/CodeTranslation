#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <stack>
#include <map>
#include <set>

#define STARTUP {(cin.tie(0));\
 (ios::sync_with_stdio(false));}

#define REP(i,a) for(int i = 0;i < (a);++i)
#define FOR(i,a,b) for(int i = (a);i < (b); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SIZE(obj) (int)(obj).size()
#define MAX(list) std::max(list)
#define MIN(list) std::min(list)
#define YESNO(cond,yes,no){cout <<((cond)?(yes):(no))<<endl; }
#define SORT(list) sort(ALL((list)));
#define RSORT(list) sort((list).rbegin(),(list).rend())
#define CINVEC(vec) REP(i,(vec).size()) cin>>(vec)[i];

template<typename T>
T round_up(const T& a, const T& b) {
    return (a + (b - 1)) / b;
}

template <typename T1, typename T2>
std::istream& operator>>(std::istream& is, std::pair<T1, T2>& p) {
    is >> p.first >> p.second;
    return is;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2>& p) {
    os << p.first << p.second;
    return os;
}

using ll = long long;
using namespace std;
ll mod = 1'000'000'007;

const int INF = 1'050'000'000;

int main() {
    STARTUP;

    char c;
    cin >> c;
    YESNO(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o', "vowel", "consonant");
    return 0;
}