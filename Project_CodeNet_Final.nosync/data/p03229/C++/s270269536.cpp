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
    vector<int> a(N, 0);
    for(int i=0; i<N; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());

    ll ans = 0;
    
    if(N%2 == 1){
        ll tmp = 0;
        for(int i=0; i<N; i++){
            if(i < (N-1)/2) tmp += 2*a[i];
            else if(i < (N-1)/2 + 2) tmp -= a[i];
            else tmp -= 2*a[i];
        }
        ans = max(ans, tmp);

        tmp = 0;
        for(int i=0; i<N; i++){
            if(i < (N-3)/2) tmp += 2*a[i];
            else if(i < (N-3)/2 + 2) tmp += a[i];
            else tmp -= 2*a[i];
        }
        ans = max(ans, tmp);
    }
    else{
        ll tmp = 0;
        for(int i=0; i<N; i++){
            if(i < N/2-1) tmp += 2*a[i];
            else if(i < N/2) tmp += a[i];
            else if(i < N/2 + 1) tmp -= a[i];
            else tmp -= 2*a[i];
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}