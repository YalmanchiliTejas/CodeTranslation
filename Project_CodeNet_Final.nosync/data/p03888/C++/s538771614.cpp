#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
REP(i,v.size()){if(i)os<<" ";os<<v[i];}return os;}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
REP(i,v.size()){if(i)os<<endl;os<<v[i];}return os;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // メインプログラムここから
    ll R1, R2; cin >> R1 >> R2;
    double R3 = (double)R1*R2/(R1+R2);
    cout << fixed << setprecision(10) << R3 << endl;
    // ここまで
}
