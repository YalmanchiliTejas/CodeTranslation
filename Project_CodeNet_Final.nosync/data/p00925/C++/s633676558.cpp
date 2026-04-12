//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <climits>
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
#include <queue>
#include <random>
#include <cctype>
#include <complex>
#include <regex>

using namespace std;

#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define SHOW_VECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOW_MAP(v) {std::cerr << #v << endl; for(const auto& xxx: v){std::cerr << xxx.first << " " << xxx.second << "\n";}}

typedef string::const_iterator ParseState;

class ParseError {
};

int expression(ParseState &begin);

int term(ParseState &begin);

int factor(ParseState &begin);

int number(ParseState &begin);

int expression(ParseState &begin) {
    int res = term(begin);
    while (true) {
        if (*begin != '+') break;
        begin++;
        res += term(begin);
    }
    return res;
}

int term(ParseState &begin) {
    int res = number(begin);
    while (true) {
        if (*begin != '*') break;
        begin++;
        res *= number(begin);
    }
    return res;
}

int factor(ParseState &begin) {

}

int number(ParseState &begin) {
    int ret = 0;
    while (isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }
    return ret;
}

int expression2(ParseState &begin) {
    int res = number(begin);
    while (true) {
        if (*begin == '+') {
            begin++;
            res += (*begin - '0');
            begin++;
            continue;
        } else if (*begin == '*') {
            begin++;
            res *= (*begin - '0');
            begin++;
            continue;
        }
        break;
    }
    return res;
}

int main() {

    //  while (true) {

    string s;
    cin >> s;

    int N;
    cin >> N;

    auto state1 = s.cbegin();
    auto state2 = s.cbegin();

    int res1 = expression(state1);
    int res2 = expression2(state2);

    //cout << res1 << res2 << endl;

    if (res1 == res2 && res1 == N) {
        cout << "U" << endl;
    } else if (res1 == N && res2 != N) {
        cout << "M" << endl;
    } else if (res1 != N && res2 == N) {
        cout << "L" << endl;
    } else {
        cout << "I" << endl;
    }

    //  }

    return 0;
}



























