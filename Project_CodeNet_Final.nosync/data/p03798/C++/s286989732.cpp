#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>


using std::cout;
using std::cin;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) {
    while (b != 0) {
        auto tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int isPrime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

bool check(int pos, string& ans, vector<int>& ord) {
    auto n = ans.size();
    auto lpos = (pos -1 + n) % n;
    auto rpos = (pos + 1) % n;
    if (ord[pos] == 1) {
        return (ans[pos] == 'o') == (ord[lpos] == ord[rpos]);
    }
    return (ans[pos] == 'o') == (ord[lpos] != ord[rpos]);
}


void oneCase () {
    int n;
    cin >> n;
    string line;
    cin >> line;
    vector<int> ans;

    vector<int> cur;
    cur.reserve(n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int l = 0;
            int ii = i;
            int jj = j;
            cur.push_back(ii);
            while (l + 1< n) {
                cur.push_back(jj);
                auto curAns = line[l + 1];
                int tmp = jj;
                if (curAns == 'o') {
                    if (jj == 1) {
                        jj = ii;
                    } else {
                        jj = 1 - ii;
                    }
                } else {
                    if (jj == 1) {
                        jj = 1 - ii;
                    } else {
                        jj = ii;
                    }
                }
                ii = tmp;
                ++l;
            }
            if (check(0, line, cur) && check(n - 1, line, cur)) {
                ans = cur;
                break;
            }

            cur.clear();
        }
        if (!ans.empty()) {
            break;
        }
    }
    if (ans.empty()) {
        cout << -1 << "\n";
    } else {
        for (auto i : ans) {
            if (i == 1) {
                cout << "S";
            } else {
                cout << "W";
            }
        }
        cout << "\n";
    }
}





int main() {
    int t = 1;
//    cin >> t;
    while (t > 0) {
        oneCase();
        --t;
    }

    return 0;
}