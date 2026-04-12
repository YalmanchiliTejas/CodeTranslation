#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// #include <set>
// #include <cmath>
// #include <map>
// #include <iomanip>

// #define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
// typedef long long ll;

// void p() {
//     cout << "\n";
// }
// template<class Head, class... Body>
// void p(Head head, Body... body) {
//     cout << head << ",";
//     p(body...);
// }

// template<typename T>
// ostream& operator<<(ostream& os, const vector<T>& v) {
//     os << "[";
//     for (const auto i : v) {
//         os << i << " ";
//     }
//     os << "]";
//     return os;
// }
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (int i=0; i < v.size(); i++) {
        os << (char)(i+'a') << ":" << v[i] << ", ";
    }
    os << "]";
    return os;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }

    vector<int> counts(26, 0);
    for (int j = 0; j < S[0].length(); ++j) {
        counts[S[0][j] - 'a'] += 1;
    }
    // cout << counts << endl;
    for (int i = 1; i < n; ++i) {
        vector<int> c(26, 0);
        for (int j = 0; j < S[i].length(); ++j) {
            c[S[i][j] - 'a'] += 1;
        }
        for (int j = 0; j < 26; ++j) {
            counts[j] = min(counts[j], c[j]);
        }
        // cout << i << " " << counts << endl;
    }

    string ans;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < counts[i]; j++) {
            ans += (char)(i+'a');
        }
    }
    cout << ans << endl;

    return 0;
}
