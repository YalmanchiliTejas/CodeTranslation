#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)

int main(){
    int N;
    long long X;
    cin >> N >> X;
    long long len[N+1];
    long long numP[N+1];
    len[0] = 1;
    numP[0] = 1;
    rep(i, N){
        len[i+1] = 2*len[i] + 3;
        numP[i+1] = 2*numP[i] + 1;
    }
    long long ans = 0;
    for(int i = N-1; i >= 0; i--){
        X--;
        if(X == 0) break;
        else if(X >= len[i]){
            ans += numP[i];
            X -= len[i];
            if(X > 0){
                ans++;
                X -= 1;
                if(X >= len[i]){
                    ans += numP[i];
                    X -= len[i];
                }
            }
            if(X == 0){
                break;
            }
        }
    }
    cout << ans << endl;
}