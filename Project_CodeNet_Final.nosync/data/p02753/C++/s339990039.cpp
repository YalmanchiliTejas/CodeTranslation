#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using Graph = vector<vector<int>>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

vector<bool> seen;

void dfs(const Graph& G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int abs_A(int num) {
    if (num > 0)
        return num;
    else
        return -num;
}

int abs_B(long long num, long long numb) {
    if (num - numb >= 0)
        return num - numb;
    else
        return -1 * (num - numb);
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

bool permutation(vector<int>& vec, vector<int>& P) {
    bool ok = true;
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) != P.at(i)) {
            ok = false;
        }
    }
    return ok;
}

const long long MOD = 1000000007;
const int INF = 1001001001;

int main() {
    string S;
    cin >> S;
    if (S.at(0) == S.at(1) && S.at(1) == S.at(2) && S.at(0) == S.at(2)) cout << "No" << endl;
    else cout << "Yes" << endl;
}
