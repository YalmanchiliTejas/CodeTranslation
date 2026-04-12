#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    sort(all(A), greater<ll>());
    ll res = -1;
    if(n%2 == 0){
        ll tmp = 0; vector<int> lst{1,-1};
        rep(i, n-2){
            if(i%2==0) lst.push_back(2);
            else lst.push_back(-2);
        }
        sort(all(lst), greater<int>());
        rep(i, n) tmp += A[i] * lst[i];
        chmax(res, tmp);
    }else{
        ll tmpA = 0, tmpB = 0; vector<int> lstA{-1,-1}, lstB{1,1};
        rep(i, n-2){
            if(i%2==0) {lstA.push_back(2); lstB.push_back(-2);}
            else {lstB.push_back(2); lstA.push_back(-2);}
        }
        sort(all(lstA), greater<int>());
        sort(all(lstB), greater<int>());

        rep(i, n){
            tmpA += A[i] * lstA[i];
            tmpB += A[i] * lstB[i];
        }
        chmax(res, tmpA);
        chmax(res, tmpB);
    }
    cout << res << ln;
}
