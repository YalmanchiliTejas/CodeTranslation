#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll L(int N){
    return (1LL<<(N+2)) - 3;
}
ll B(int N){
    return (1LL<<(N+1)) - 1;
}

int main(){
    ll N, X;
    cin >> N >> X;

    ll ans = 0;
    for(int i=N;i>=0;i--){
        if(X <= 1){
            if(i==0 && X==1) ans++;
            cout << ans << endl;
            return 0;
        }
        if(X > L(i-1)+1){
            ans += B(i-1) + 1;
            X -= L(i-1) + 1;
        }
        X--;
    }
    cout << ans << endl;
    
    return 0;
}
