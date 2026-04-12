#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
template<typename T> using VT = vector<T>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back
template<typename T>inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

vector<string> split(const string &originalStr, char sep) {
    vector<string> res;
    string element = "";
    for (const char c : originalStr) {
        if (c == sep) {
            res.emplace_back(element);
            element.clear();
        } else {
            element += c;
        }
    }
    if (!element.empty()) {
        res.emplace_back(element);
    }
    return res;
}

char strbuf[1000];
string S;
int ans;

int leftToRightCalc(string s) {
    const int L = s.length();
    if (L == 0) return 0;
    int res = s[0] - '0';
    bool premul = false;
    FOR(i, 1, L) {
        if (isdigit(s[i])) {
            if (premul) {
                res *= s[i] - '0';
            } else {
                res += s[i] - '0';
            }
        } else {
            premul = s[i] == '*';
        }
    }
    return res;
}
int mul(string s) {
    if (s.length() == 0) return 0;
    int res = s[0] - '0';
    FOR(i, 1, s.length()) {
        if (isdigit(s[i])) {
            res *= s[i] - '0';
        }
    }
    //DEBUG(res)
    return res;
}
int mulFirstCalc(string s) {
    VT<string> S = split(s, '+');
    int res = 0;
    FORE(e, S) {
        //DEBUG(e)
        if (e.length() == 1) res += e[0] - '0';
        else res += mul(e);
    }
    return res;
}

int main(void) {
    scanf("%s", strbuf);
    S = strbuf;
    scanf("%d", &ans);
    int ltr = leftToRightCalc(S);
    int mf = mulFirstCalc(S);
    //DEBUG(ltr)DEBUG(mf)
    if (ans == mf && ans != ltr) {
        puts("M");
    } else if (ans != mf && ans == ltr) {
        puts("L");
    } else if (ans == mf && ans == ltr) {
        puts("U");
    } else {
        puts("I");
    }
}