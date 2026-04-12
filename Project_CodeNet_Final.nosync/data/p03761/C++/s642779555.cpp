#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;
const double PI = acos(-1);

int main() {
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(26, 0));
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        for (auto c : S) A[i][c - 'a']++;
    }

    vector<int> B(26, MAX);
    for (int i = 0; i < 26; i++) for (int j = 0; j < N; j++) chmin(B[i], A[j][i]);

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < B[i]; j++) {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;
    return 0;
}