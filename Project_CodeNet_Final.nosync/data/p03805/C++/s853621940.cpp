#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;

void solve(vector<vector<int>> &A, vector<bool> check, int &ans, int now){
    check.at(now) = true;
    bool T = false;
    for (int i = 0; i < A.at(now).size(); i++){
        if (check.at(A.at(now).at(i))) {
            continue;
        }
        solve(A, check, ans, A.at(now).at(i));
        T = true;
    }
    if (!T) {
        for (int i = 0; i < check.size(); i++) {
            if (!check.at(i)){
                break;
            }
            if (i == check.size() - 1) {
                ans++;
            }
        }
    }
    return;

}

int main() {
    int N, M, ans = 0;
    cin >> N >> M;
    vector<vector<int>> A(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        A.at(a - 1).emplace_back(b - 1);
        A.at(b - 1).emplace_back(a - 1);
    }
    vector<bool> check(N, false);
    solve(A, check, ans, 0);
    cout << ans << endl;
}