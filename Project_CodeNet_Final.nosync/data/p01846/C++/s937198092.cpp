#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

long long mod_pow(long long x, long long n) {
    long long res = 1;
    for(int i = 0;i < 60; i++){
        if(n >> i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

template<typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

void fast_input() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}
vector<vector<int>> jtof(string S) {
    S.push_back('/');
    vector<vector<int>> ret;
    vector<int> tmp;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'b') {
            tmp.push_back(0);
        } else if (S[i] == '/') {
            ret.push_back(tmp);
            tmp.clear();
        } else {
            int num = (int)(S[i] - '0');
            for (int j = 0; j < num; j++) {
                tmp.push_back(1);
            }
        }
    }
    return ret;
}

string ftoj(vector<vector<int>> field) {
    string ret;
    for (int i = 0; i < field.size(); i++) {
        int cnt = 0;
        for (int j = 0; j < field[i].size(); j++) {
            if (field[i][j] == 1) {
                cnt++;
            } else if (field[i][j] == 0){
                if (cnt) ret.push_back('0' + cnt);
                cnt = 0;
                ret.push_back('b');
            }
            if (field[i].size() - 1 == j) {
                if (cnt) ret.push_back('0' + cnt);
                ret.push_back('/');
            }
        }
    }
    return ret;
}


string solve(string S) {
    vector<vector<int>> field = jtof(S);
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    field[a][b] = 1;
    field[c][d] = 0;
    string ret = ftoj(field);
    return ret;
}

int main(void) {
    string S;
    vector<string> ans;
    while (1) {
        cin >> S;
        if (S[0] == '#') break;
        ans.push_back(solve(S));
    }
    for (auto &i : ans) {
        for (int j = 0; j < i.length() - 1; j++) {
            if (j != i.length() - 2) cout << i[j];
            else cout << i[j] << endl;
        }
    }
}   

