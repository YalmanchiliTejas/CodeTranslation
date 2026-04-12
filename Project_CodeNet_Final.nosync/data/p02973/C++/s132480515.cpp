/*
    Problem 55
    https://atcoder.jp/contests/abc134/tasks/abc134_e
*/
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
    reverse(a.begin(), a.end());
    vector<int> LIS(N+1, INF);
    for (int i = 0; i < N; i++) {
        *upper_bound(LIS.begin(), LIS.end(), a[i]) = a[i];
    }
    cout << lower_bound(LIS.begin(), LIS.end(), INF) - LIS.begin() << '\n';
}