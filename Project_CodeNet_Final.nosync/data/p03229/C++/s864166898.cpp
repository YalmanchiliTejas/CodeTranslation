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

int main() {
    int N; cin >> N;
    vecl A(N); REP(i,N) cin >> A[i];
    vecl B(N),C(N);
    sort(A.begin(),A.end());
    if(N == 2) {
        cout << abs(A[0]-A[1]) << endl;
        return 0;
    }
    if(N%2 == 0) {
        vecl small,large;
        ll s = 0;
        REP(i,N) if(i < N/2) small.push_back(A[i]);
        else large.push_back(A[i]);
        REP(i,N/2) {
            //cout << small[i] <<" " << large[i] << endl;
            if(i == N/2-1) {
                s -= small[i];
                s += 2*large[i];
            } else if(i == 0) {
                s -= 2*small[i];
                s += large[i];
            } else {
                s -= 2*small[i];
                s += 2*large[i];
            }
        }
        cout << s << endl;
    } else {
        deque<ll> small,large,B,C;
        REP(i,N) if(i < N/2+1) small.push_back(A[i]);
        else large.push_back(A[i]);
        ll s = 0;
        REP(i,N/2) s += 2*large[i];
        REP(i,N/2+1) if(i < N/2-1) s -= 2*small[i];
        else s -= small[i];
        large.push_front(small.back());
        small.pop_back();
        ll t = 0;
        REP(i,N/2) t -= 2*small[i];
        REP(i,N/2+1) if(i < 2) t += large[i];
        else t += 2*large[i];
        cout << max(s,t) << endl;
    }
}