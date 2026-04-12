#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> L(N + 1);
    L[0] = a[N-1];
    int length = 1;
    for (int i = N-2; i >= 0; i--) {
        if (L[length - 1] <= a[i]) L[length++] = a[i];
        else {
            *upper_bound(L.begin(), L.begin() + length, a[i]) = a[i];
        }
    }
    cout << length << '\n';
}
