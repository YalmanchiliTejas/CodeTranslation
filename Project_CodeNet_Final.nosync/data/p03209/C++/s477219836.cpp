#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N,X;
    cin >> N >> X;
    long long ans =0;
    long long S[55], P[55]; //レベルiバーガーの長さ,パティの数
    S[0]=1; P[0]=1;
    for(int i=0; i<50; i++){
        S[i+1] = 2* S[i] + 3;
        P[i+1] = 2* P[i] + 1;
    }


    for(int i=N; i>0; i--){
        if(X > S[i-1]+1) {
            ans += P[i-1]+1;
            X -= S[i-1]+2;
            continue;
        }
        if(X <= S[i-1]+1) {
            X--;
            continue;
        }
    }
    if(X>=1) ans++;
    cout << ans << endl;
}