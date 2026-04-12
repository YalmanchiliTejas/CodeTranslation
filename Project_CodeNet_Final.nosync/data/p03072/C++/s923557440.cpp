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
    vector<int> h(N);
    for(int i=0; i<N; i++){
        cin >> h[i];
    }

    int ans = 0;
    int highest = h[0];

    for(int i=0; i<N; i++){
        if(highest <= h[i]){
            ans++;
            highest = h[i];
        }
    }

    cout << ans << endl;
}