#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

ll N, X;
ll a[55], p[55];

ll solve(ll N, ll X){
    if(N==0) return 1;

    if(X==1) return 0;
    else if(X <= 1+a[N-1]) return solve(N-1, X-1);
    else if(X == 1+a[N-1]+1) return p[N-1]+1;
    else if(X <= 1+a[N-1]+1+a[N-1]) return p[N-1]+1+solve(N-1, X-a[N-1]-2);
    else return p[N];
}

int main(){
    cin >> N >> X;
    a[0] = 1;
    p[0] = 1;

    for(int i=1; i<=N; i++) { a[i] = 2*a[i-1]+3; p[i] = 2*p[i-1]+1; }
    
    cout << solve(N, X) << endl;
}