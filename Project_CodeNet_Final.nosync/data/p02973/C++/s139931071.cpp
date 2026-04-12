#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;
const int MOD = 1000000007;
const double pi = acos(-1);

const int INF = 1e9 + 1;
vecveci Li(100010);
veci ma(100010,-1);

int main() {
    int N; cin >> N;
    veci A(N);
    REP(i,N) cin >> A[i];
    REP(i,N) {
        int l = -1, r = N;
        while(r-l > 1) {
            int mid = (r+l)/2;
            if(ma[mid] >= A[i]) l = mid;
            else r = mid;
        }
        Li[r].push_back(A[i]);
        ma[r] = A[i];
    }
    /*
    REP(i,N) {
        for(auto x : Li[i]) cout << x << " " ;
        cout << endl;
    }
    */
    int ans = 0;
    REP(i,100010) if(Li[i].size()) ans++;
    cout << ans << endl;
}