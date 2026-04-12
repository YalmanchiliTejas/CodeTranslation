#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int A[100010];
    rep(i, n) cin >> A[i];
    sort(A, A + n);
    int ans = 0;
    
    vector<int> v;
    
    deque<int> deq1, deq2;
    int sum = 0;
    int l = 0, r = n - 1;
    deq1.push_back(A[l++]);
    while(l <= r) {
        if(l <= r)
            deq1.push_back(A[r--]);
        if(l <= r)
            deq1.push_front(A[r--]);
        if(l <= r)
            deq1.push_back(A[l++]);
        if(l <= r)
            deq1.push_front(A[l++]);
    }
    rep(i, n - 1) sum += abs(deq1[i] - deq1[i + 1]);
    // rep(i, n) cout << deq1[i] << " ";
    // cout << endl;
    ans = sum;
    sum = 0;
    l = 0, r = n - 1;
    deq2.push_back(A[r--]);
    while(l <= r) {
        if(l <= r)
            deq2.push_back(A[l++]);
        if(l <= r)
            deq2.push_front(A[l++]);
        if(l <= r)
            deq2.push_back(A[r--]);
        if(l <= r)
            deq2.push_front(A[r--]);

    }
    // rep(i, n) cout << deq2[i] << " ";
    // cout << endl;
    rep(i, n - 1) sum += abs(deq2[i] - deq2[i + 1]);
    ans = max(ans, sum);
    cout << ans << endl;
   
    return 0;
}

// 1 7 3 5
// 7 1 5 3