#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

bool check(vector<int>& wolf, const string S) {
    int N = S.size();
    for (int i = 0; i < N; i++) {
        int prev = i - 1;
        if (prev < 0) prev = N - 1;
        int next = i + 1;
        if (next >= N) next = 0;
        if ((S[i] == 'o' && wolf[i] == 2) || (S[i] == 'x' && wolf[i] == 1)) {
            if (wolf[prev] != 0 && wolf[prev] == wolf[next]) continue;
            if (wolf[prev] == 0) {
                wolf[prev] = wolf[next];
                continue;
            } else if (wolf[next] == 0) {
                wolf[next] = wolf[prev];
                continue;
            } else {
                return false;
            }
        } else {
            if (wolf[prev] != 0 && wolf[next] != 0 && wolf[prev] != wolf[next]) continue;
            if (wolf[prev] == 0) {
                if (wolf[next] == 1) wolf[prev] = 2;
                else wolf[prev] = 1;
            } else if (wolf[next] == 0) {
                if (wolf[prev] == 1) wolf[next] = 2;
                else wolf[next] = 1;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N; cin >> N;
    string S; cin >> S;

    // 0: unknown 1: wolf 2:sheep
    vector<int> wolf(N);
    
    for (int j = 0; j < N; j++) wolf[j] = 0;
    wolf[0] = 1; wolf[1] = 1;
    if (check(wolf, S)) goto END;

    for (int j = 0; j < N; j++) wolf[j] = 0;
    wolf[0] = 1; wolf[1] = 2;
    if (check(wolf, S)) goto END;

    for (int j = 0; j < N; j++) wolf[j] = 0;
    wolf[0] = 2; wolf[1] = 1;
    if (check(wolf, S)) goto END;

    for (int j = 0; j < N; j++) wolf[j] = 0;
    wolf[0] = 2; wolf[1] = 2;
    if (check(wolf, S)) goto END;
    cout << -1 << endl;
    return 0;

END:
    for (int i = 0; i < N; i++) {
        if (wolf[i] == 1) cout << 'W';
        else cout << 'S';
    }
    cout << '\n';
}
