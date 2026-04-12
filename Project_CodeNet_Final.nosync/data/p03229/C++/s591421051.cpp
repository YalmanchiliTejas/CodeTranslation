#ifdef _DEBUG
#include "MyLib.h"
#else
#define main_C main
#include "bits/stdc++.h" 
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#define FOR(i,s,e) for (int i = int(s); i < int(e); ++i)
#define REP(i,e) FOR(i,0,e)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LONG_MAX/2)
const int MGN = 8;
const int ARY_SZ_MAX = 10000000;
using namespace std;
using ll = long long; using ull = unsigned long long;
using vi = vector<int>; using vvi = vector<vi>; using vvvi = vector<vvi>;
using vb = vector<bool>; using vvb = vector<vb>; using vvvb = vector<vvb>;
using vl = vector<ll>; using vvl = vector<vl>;
using vd = vector<double>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>;
// functions
bool second_greater(const pii& left, const pii& right) {
    return left.second > right.second;
}
#endif

ll calc(vi& A, int mid) {
    const int N = A.size();
    deque<int> dq;
    dq.push_back(A[mid]);
    priority_queue<int> pqhi;
    priority_queue<int, vi, greater<int> > pqlo;
    FOR(i,0,N) {
        if (i == mid) continue;
        pqhi.push(A[i]);
        pqlo.push(A[i]);
    }

    int cnt = 0;
    int oddEven = 0;
    if (mid > 0) oddEven = 1;
    while(dq.size() < N) {
        if (cnt%2==oddEven) {
            dq.push_front(pqhi.top());
            pqhi.pop();
            if (dq.size()<N) {
                dq.push_back(pqhi.top());
                pqhi.pop();
            }
        } else {
            dq.push_front(pqlo.top());
            pqlo.pop();
            if (dq.size()<N) {
                dq.push_back(pqlo.top());
                pqlo.pop();
            }
        }
        cnt++;
    }

    ll sum = 0;
    int cur = dq.front(); dq.pop_front();
    while(!dq.empty()){
        int next = dq.front(); dq.pop_front();
        sum += abs(next - cur);
        cur = next;
    }
    return sum;
}

int main_C() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;  cin >> N;
    vi A(N); REP(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    ll ans = max(calc(A, 0), calc(A, N-1));

    cout << ans << endl;

    return 0;
}