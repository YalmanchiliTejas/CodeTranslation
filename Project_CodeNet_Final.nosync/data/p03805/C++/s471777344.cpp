#include <iostream>
#include <vector>
// #include <string>
// #include <map>
// #include <algorithm>
// #include <set>
// #include <cmath>

using namespace std;
// typedef unsigned long long ull;

void display_base(int n, int b) {
    vector<int> v;
    int n_ = n;
    while(n_ > 0) {
        v.push_back(n_ % b);
        n_ /= b;
    }
    cout << n << "(" << b << ") = ";
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }
    cout << endl;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (const auto i : v) {
        os << i << " ";
    }
    os << "]";
    return os;
}

int dfs(int idx, unsigned int visited, const vector<vector<int>>& C) {
    visited |= (1 << idx);

    int N = C.size();
    if (visited == ((1 << N) - 1)) {
        return 1;
    }

    // cout << "idx = " << idx << endl;
    // display_base(visited, 2);

    int ret = 0;
    for (int to : C[idx]) {
        if (!((visited >> to) & 1)) {
            // cout << "to: " << to << endl;
            // ret += dfs(to, visited, C);
            int tmp = dfs(to, visited, C);
            ret += tmp;
            // cout << "to: " << to << "  tmp: " << tmp << endl;
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> C(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        C[a-1].push_back(b-1);
        C[b-1].push_back(a-1);
    }

    // cout << C << endl;

    cout << dfs(0, 0, C) << endl;
    return 0;
}
