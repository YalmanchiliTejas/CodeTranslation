#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define REP(i, n) FOR(i, 0, n)
#define INF 999999999
typedef long long ll;
using namespace std;
int main() {
    int N, K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;
    char c = S[K-1];
    REP(i, S.length()) {
        if(S[i] != c) S[i] = '*';
    }
    cout << S << endl;
}