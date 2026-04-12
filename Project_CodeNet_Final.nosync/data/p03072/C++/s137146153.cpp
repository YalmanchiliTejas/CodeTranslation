//url:
//problem name:

#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<long long,long long>;
using veci = vector<int>;
using vecl = vector<long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N;
    cin >> N;
    veci H(N);
    REP(i,N) cin >> H[i];
    int ans = 0;
    REP(i,N) {
        bool ok = true;
        for(int j = 0; j < i; j++) {
            if(H[i] < H[j]) ok = false;
        }
        ans += ok;
    }
    cout << ans << endl;
}