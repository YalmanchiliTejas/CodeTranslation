#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int> (26));
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < S.size(); j++) {
            A.at(i).at(S.at(j) - 'a')++;;
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < 26; j++) {
            A.at(i + 1).at(j) = min(A.at(i + 1).at(j), A.at(i).at(j));
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < A.at(N - 1).at(i); j++) {
            char B = 'a' + i;
            cout << B;
        }
    }
    cout << endl;
}