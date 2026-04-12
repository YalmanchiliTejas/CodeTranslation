#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, k, n) for(auto i = k; i != n; i++)
#define rrep(i, n) RREP(i, n, 0)
#define RREP(i, n, k) for(auto i = n; i != k; i--)
#define all(x, r) (x), (x)+(r)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " " << x << endl
#define exst(x, data) (data).find(x) != (data).end()
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define np next_permutation
#define b32 bitset<32>

using ll = long long;
using Pii = pair<int,int>;
using Tiii = tuple<int, int, int>;
template<class T>using V = vector<T>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N; cin >> N;
    V<ll> A = V<ll>(N); rep(i,N) cin >> A[i];
    sort(ALL(A));
    ll ans = 0;

    if(A.size() == 2) {
        cout << abs(A[0] - A[1]) << endl;
        return 0;
    }

    V<ll> B = V<ll>(A);
    ll t_ans = abs(B[N-1] - B[1]) + abs(B[N-1] - B[0]);
    ll last[2]; last[0] = B[1], last[1] = B[0];
    rep(i,2) B.erase(B.begin()); B.erase(B.end()-1);

    while(B.size() > 0) {
        if(B.size() >= 2) {
            t_ans += abs(last[0] - B[B.size()-1]) + abs(last[1] - B[B.size()-2]);
            last[0] = B[B.size()-1]; last[1] = B[B.size()-2];
            B.erase(B.end()-1); B.erase(B.end()-1);
        } else {
            t_ans += abs(min(last[0], last[1]) - B[0]);
            break;
        }
        // cout << "a" << endl;

        if(B.size() == 0) break;
        else if(B.size() >= 2) {
            // cout << "b1" << endl;
            t_ans += abs(last[0] - B[0]) + abs(last[1] - B[1]);
            last[0] = B[0]; last[1] = B[1];
            B.erase(B.begin()); B.erase(B.begin());
            // cout << "b2" << endl;
        } else {
            t_ans += abs(max(last[0], last[1]) - B[0]);
            break;
        }
        // cout << "b" << endl;
    }
    ans = max(ans, t_ans);

    B = V<ll>(A);
    t_ans = abs(B[0] - B[N-1]) + abs(B[0] - B[N-2]);
    last[0] = B[N-1], last[1] = B[N-2];
    rep(i,2) B.erase(B.end()-1); B.erase(B.begin());

    while(B.size() > 0) {
        if(B.size() >= 2) {
            // cout << "b1" << endl;
            t_ans += abs(last[0] - B[0]) + abs(last[1] - B[1]);
            last[0] = B[0]; last[1] = B[1];
            B.erase(B.begin()); B.erase(B.begin());
            // cout << "b2" << endl;
        } else {
            t_ans += abs(max(last[0], last[1]) - B[0]);
            break;
        }

        if(B.size() == 0) break;
        else if(B.size() >= 2) {
            t_ans += abs(last[0] - B[B.size()-1]) + abs(last[1] - B[B.size()-2]);
            last[0] = B[B.size()-1]; last[1] = B[B.size()-2];
            B.erase(B.end()-1); B.erase(B.end()-1);
        } else {
            t_ans += abs(min(last[0], last[1]) - B[0]);
            break;
        }
    }
    ans = max(ans, t_ans);

    cout << ans << endl;
    return 0;
}
