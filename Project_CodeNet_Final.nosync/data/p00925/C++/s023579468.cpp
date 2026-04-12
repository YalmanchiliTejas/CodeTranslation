#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>

#define INF (int)1e09

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
using std::pair;
using std::make_pair;
using std::min;
using std::max;
using std::string;
using std::vector;
using std::list;
using std::map;
using std::set; // insert erase find count
using std::queue;
using std::priority_queue;
using std::stack;

template <typename T> using Vec = vector<T>; // c++11
typedef pair<int, int> PII;
typedef pair<int, pair<int, int> > PIII;

int main(void) {
    string exp;
    cin >> exp;
    const int exp_len = (int)exp.length();
    int co_ans;
    cin >> co_ans;

    stack<int> calc_m;
    for (int i = 0; i < exp_len; i++) {
        if (i % 2 == 0) {
            calc_m.push((int)(exp[i] - '0'));
        } else {
            if (exp[i] == '*') {
                int mul = calc_m.top() * ((int)(exp[i + 1] - '0'));
                calc_m.pop();
                calc_m.push(mul);
                i++;
            }
        }
    }

    int m = 0;
    while (!calc_m.empty()) {
        m += calc_m.top();
        calc_m.pop();
    }

    int l = exp[0] - '0';
    for (int i = 1; i < exp_len; i++) {
        if (i % 2 == 1) {
            if (exp[i] == '*') {
                l *= (exp[i + 1] - '0');
            } else {
                l += (exp[i + 1] - '0');
            }
        }
    }

    if (co_ans == m && co_ans == l) {
        cout << 'U' << endl;
    } else if (co_ans == m) {
        cout << 'M' << endl;
    } else if (co_ans == l) {
        cout << 'L' << endl;
    } else {
        cout << 'I' << endl;
    } 

    return 0;
}