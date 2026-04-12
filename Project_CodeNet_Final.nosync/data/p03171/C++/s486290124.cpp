#include <bits/stdc++.h>
using namespace std;

class Debug {
private:
    static int NAME_LENGTH, MAX_WIDTH;
    static bool IS_MATRIX;
    static long long INF;
public:
    static void set_NAME_LENGTH(int l) { NAME_LENGTH = l; }
    static int get_NAME_LENGTH() { return NAME_LENGTH; }
    static void set_MAX_WIDTH(int w) { MAX_WIDTH = w; }
    static int get_MAX_WIDTH() { return MAX_WIDTH; }
    static void set_IS_MATRIX(bool f) { IS_MATRIX = f; }
    static bool get_IS_MATRIX() { return IS_MATRIX; }
    static void set_INF(long long i) { INF = i; }
    static long long get_INF() { return INF; }
};

int Debug::NAME_LENGTH = 0;
int Debug::MAX_WIDTH = 0;
bool Debug::IS_MATRIX = false;
long long Debug::INF = LLONG_MAX;

// Debug for vector
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool flg = true;
    for (auto e : v) {
        os << (flg ? "" : ", ");
        if (Debug::get_IS_MATRIX()) {
            os << right << setw(Debug::get_MAX_WIDTH());
        }
        if (e == Debug::get_INF()) os << "INF";
        else os << e;
        flg = false;
    }
    os << "]";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
    Debug::set_IS_MATRIX(true);
    int width = 0;
    for (unsigned int i = 0; i < v.size(); ++i) {
        for (unsigned int j = 0; j < v[i].size(); ++j) {
            if (v[i][j] == Debug::get_INF()) width = max(width, (int)("INF"s.size()));
            else width = max(width, (int)to_string(v[i][j]).size());
        }
    }
    Debug::set_MAX_WIDTH(width);
    string space = "";
    for (int i = 0; i < Debug::get_NAME_LENGTH() + 7; ++i) space += " ";
    os << "[";
    bool flg = true;
    for (auto e : v) {
        os << (flg ? "" : "\n" + space);
        os << e;
        flg = false;
    }
    os << "]";
    Debug::set_IS_MATRIX(false);
    return os;
}

// Debug for pair
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// Debug for set
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool flg = true;
    for (auto e : s) {
        os << (flg ? "" : ", ");
        os << e;
        flg = false;
    }
    os << "}";
    return os;
}

// Debug for map
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
    os << "{";
    bool flg = true;
    for (auto e : mp) {
        os << (flg ? "" : ", ");
        os << e.first << ": " << e.second;
        flg = false;
    }
    os << "}";
    return os;
}

// Debug for queue
template <typename T>
ostream& operator<<(ostream& os, const queue<T>& que) {
    queue<T> que_cp = que;
    os << "[";
    bool flg = true;
    while (!que_cp.empty()) {
        os << (flg ? "" : ", ");
        os << que_cp.front();
        que_cp.pop();
        flg = false;
    }
    os << "]";
    return os;
}

// Debug for deque
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& que) {
    os << "[";
    bool flg = true;
    for (auto e : que) {
        os << (flg ? "" : ", ");
        os << e;
        flg = false;
    }
    os << "]";
    return os;
}

// Debug assistant
#define DUMP(...) INTERNAL_DUMP(#__VA_ARGS__, __VA_ARGS__)

string REMOVE_SPACE(string s) {
    while (s[0] == ' ') {
        s = s.substr(1);
    }
    while (s[s.size() - 1] == ' ') {
        s = s.substr(0, s.size() - 1);
    }
    return s;
}

pair<string, string> GET_NAME(string s) {
    int bracket = 0, idx = 0;
    while ((unsigned)idx < s.size() && !(s[idx] == ',' && bracket == 0)) {
        if (s[idx] == '(') ++bracket;
        else if (s[idx] == ')') --bracket;
        ++idx;
    }
    string other_names;
    if ((unsigned)idx == s.size()) {
        other_names = "";
    } else {
        other_names = s.substr(idx + 1);
    }
    string first_name = s.substr(0, idx);
    first_name = REMOVE_SPACE(first_name);
    other_names = REMOVE_SPACE(other_names);
    return pair<string, string>(first_name, other_names);
}

// Debug main
void INTERNAL_DUMP(string name) {
    return;
}

template <class Head, class... Tail>
void INTERNAL_DUMP(string name, Head&& head, Tail&&... tail) {
    pair<string, string> p = GET_NAME(name);
    Debug::set_NAME_LENGTH(p.first.size());
    cerr << ">> " << p.first << " = " << head << endl;
	INTERNAL_DUMP(p.second, move(tail)...);
}

// End of Debug parts
//------------------------------------------------------------------------------


const long long INF = 1LL << 60;
vector<long long> a;
vector<vector<long long>> dp;

bool flip(bool turn) {
    return turn ? false : true;
}

int sign(bool turn) {
    return turn ? 1 : -1;
}

long long dfs(int i, int j, bool turn) {
    if (dp[i][j] != INF) return dp[i][j];
    if (turn) dp[i][j] = max(dfs(i + 1, j, flip(turn)) + sign(turn) * a[i], dfs(i, j - 1, flip(turn)) + sign(turn) * a[j]);
    else dp[i][j] = min(dfs(i + 1, j, flip(turn)) + sign(turn) * a[i], dfs(i, j - 1, flip(turn)) + sign(turn) * a[j]);
}

int main() {
    Debug::set_INF(INF);
    int N;  cin >> N;
    a.resize(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    dp.resize(N, vector<long long>(N));
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) dp[i][j] = INF;
    for (int i = 0; i < N; ++i) dp[i][i] = sign(N % 2) * a[i];
    cout << dfs(0, N - 1, true) << endl;
    // DUMP(dp);
}
