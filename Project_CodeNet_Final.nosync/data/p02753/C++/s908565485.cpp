#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define rep1(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep2(i, n, m) for (long long i = (long long)(n); i <= (long long)(m); i++)
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    string out = (s.at(0) == s.at(1) && s.at(1) == s.at(2)) ? "No" : "Yes";
    cout << out << endl;
}
