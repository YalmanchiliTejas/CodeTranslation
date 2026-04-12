#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> memo = {-1};
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        int n = memo.size();
        int ok = n, ng = -1;
        while (ok - ng != 1) {
            int med = (ok + ng) / 2;
            if (memo[med] < a) {
                ok = med;
            } else {
                ng = med;
            }
        }
        if (ok == n) {
            memo.push_back(a);
        } else {
            memo[ok] = a;
        }
    }
    cout << memo.size() << endl;
}
