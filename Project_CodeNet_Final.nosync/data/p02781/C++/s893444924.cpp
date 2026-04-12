#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> i_i;

#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define ALL(v) v.begin(), v.end()
#define SZ(x) ((int)(x).size())

const double PI  = acos(-1.0);
const double EPS = 1e-9;
const ll INF = 1e9+10;
const ll mod = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define print(x) cerr << #x << " is " << x << endl;
//#define print(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl; 

int A[200];

ll g(int n, int k){
    if (k == 0)
        return 1;
    if (k == 1)
        return n * 9;
    if (k == 2)
        return n * (n - 1)/2 * 9 * 9;
    assert(0);
}
 
ll f(int now, int n, int k){
    ll ans = 0;
    if (n < k){
        return 0;
    }
        
    if (k == 0){
        return 1;
    }

    // now == 0
    //if (now != 0)
    //    ans += f(now + 1, n - 1, k);
    if (0 && now != 0 && A[now] != 0){ //now != 0/* && A[now] != 0*/){
        ans += g(n - 1, k);
    }
    reps(i, 0, A[now] + 1){
        if (now == 0 && i == 0)continue;
        if (i == A[now]){
            if (i == 0){
                ans += f(now + 1, n - 1, k);
            } else {
                ans += f(now + 1, n - 1, k - 1);
            }

        } else {
            if (i == 0){
                ans += g(n - 1, k);
            } else {
            ans += g(n - 1, k - 1);
            }
        }
    }
    return ans;
}
    
//
int main() {
    string S;
    cin >> S;
    int N = S.size(), K;
    rep(i, N){
        A[i] = S[i] - '0';
        //cout << A[i];
    }
    //cout << endl;
    ll ans = 0;
    cin >> K;
    
    // N - 1 ���ȉ�  n-1 C k 9^k  
    if (K == 3){
        ans = (N - 1) * (N - 2) * (N - 3) / 6 * 9 * 9 * 9;
    } else if (K == 2){
        ans = (N - 1) * (N - 2) / 2 * 9 * 9;
    } else if (K == 1){
        ans = (N - 1) * 9;
    }
    //cout << ans << endl;
    ans += f(0, N, K);
    cout << ans;
    return 0;
}
