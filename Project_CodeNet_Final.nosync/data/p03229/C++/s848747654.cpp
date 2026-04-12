#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<ll, ll>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    deque<ll> A(N);
    rep(i, N) cin >> A[i];
    deque<ll> B = A;
    sort(all(A));
    sort(all(B));
    deque<ll> dQ;
    deque<ll> dQt;
    dQ.pb(A[0]);A.pop_front();
    int cnt = 0;
    while(!A.empty()) {
        if(cnt % 4 < 2) {
            if(cnt % 2 == 0) {
                dQ.pb(A.back());
            }else {
                dQ.push_front(A.back());
            }
            A.pop_back();
        }else {
            if(cnt % 2 == 0) {
                dQ.pb(A.front());
            }else {
                dQ.push_front(A.front());
            }
            A.pop_front();
        }
        ++cnt;
    }
    ll ans = 0;
    rep(i, N - 1) {
        ans += abs(dQ[i] - dQ[i + 1]);
    }

    dQt.pb(B[N - 1]);B.pop_back();
    cnt = 0;
    while(!B.empty()) {
        if(cnt % 4 >= 2) {
            if(cnt % 2 == 0) {
                dQt.pb(B.back());
            }else {
                dQt.push_front(B.back());
            }
            B.pop_back();
        }else {
            if(cnt % 2 == 0) {
                dQt.pb(B.front());
            }else {
                dQt.push_front(B.front());
            }
            B.pop_front();
        }
        ++cnt;
    }
    ll anst = 0;
    rep(i, N - 1) {
        anst += abs(dQt[i] - dQt[i + 1]);
    }
    cout << max(ans, anst) << endl;
}
