/*
    Problem 55
    https://atcoder.jp/contests/abc134/tasks/abc134_e
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> LIS;
    for (int i = 0; i < A.size(); i++) {
        auto itr = lower_bound(LIS.begin(), LIS.end(), A[i], greater_equal<int>());
        if (itr == LIS.end())
            LIS.push_back(A[i]);
        else
            *itr = A[i];
    }
    cout << LIS.size() << '\n';
}
