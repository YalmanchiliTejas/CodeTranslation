#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 100005;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<int> A(MAX), L(MAX, -1), D;
    for (int i = 0; i < N; i++) cin >> A[i];
    L[0] = A[0];
    D.push_back(INF);
    int length = 1;
    for (int i = 1; i < N; i++) {
        if (L[length - 1] < A[i]) L[length++] = A[i];
        else {
            int ind = lower_bound(L.begin(), L.begin() + length, A[i]) - L.begin();
            int d = L[ind];
            L[ind] = A[i];
            if (d == -1) { continue; }
            auto itr = lower_bound(D.begin(), D.end(), d);
            if (itr == D.begin()) {
                D.insert(D.begin(), {d});
            }
            else *(itr - 1) = d;
        }
    }
    int ans = 1;
    if (D[0] != INF) ans += D.size() - 1;
    cout << ans << '\n';
}
