#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
*/

int main(){
    int N; cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];

    int ans = 1;
    int maxv = a[0];
    for(int i=1; i<N; i++){
        if(a[i] >= maxv) ans++;
        maxv = max(maxv, a[i]);
    }

    cout << ans << endl;
}