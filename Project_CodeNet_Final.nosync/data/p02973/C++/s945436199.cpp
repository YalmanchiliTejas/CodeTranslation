#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];

    deque<int> dq;
    rep(i,n){
        int p = lower_bound(ALL(dq),a[i]) - dq.begin();
        // a[i]以上の最初の添字
        if(p==0)dq.push_front(a[i]);
        else dq[p-1] = a[i];
    }
    cout << dq.size() << endl;
}