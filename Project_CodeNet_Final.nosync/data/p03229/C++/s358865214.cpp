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


int main_C() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;  cin >> N;
    vi A(N); REP(i, N) cin >> A[i];

    sort(A.begin(), A.end());

    deque<int> dq;
    dq.push_back(A[0]);
    int cnt = 0;
    int left = 1, right = N - 1;
    while(left <= right) {
        if (cnt%2==0) {
            dq.push_front(A[right]);
            right--;
            if (left <= right) {
                dq.push_back(A[right]);
                right--;
            }
        } else {
            dq.push_front(A[left]);
            left++;
            if (left <= right) {
                dq.push_back(A[left]);
                left++;
            }
        }
        cnt++;
    }

    ll ans = 0;
    ll sum = 0;
    int cur = dq.front(); dq.pop_front();
    while(!dq.empty()){
        int next = dq.front(); dq.pop_front();
        sum += abs(next - cur);
        cur = next;
    }
    ans = max(ans, sum);

    dq.clear();
    dq.push_back(A[N-1]);
    cnt = 0;
    left = 0, right = N - 2;
    while(left <= right) {
        if (cnt%2==1) {
            dq.push_front(A[right]);
            right--;
            if (left <= right) {
                dq.push_back(A[right]);
                right--;
            }
        } else {
            dq.push_front(A[left]);
            left++;
            if (left <= right) {
                dq.push_back(A[left]);
                left++;
            }
        }
        cnt++;
    }

    sum = 0;
    cur = dq.front(); dq.pop_front();
    while(!dq.empty()){
        int next = dq.front(); dq.pop_front();
        sum += abs(next - cur);
        cur = next;
    }
    ans = max(ans, sum);


    cout << ans << endl;

    return 0;
}