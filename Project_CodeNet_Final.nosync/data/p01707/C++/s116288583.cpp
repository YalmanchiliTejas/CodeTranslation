#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1000000007;

long long D, N, X;

long long mtr[2002], tmp[2002], vec[2002];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin >> N >> D >> X && (N||D||X)){
        fill(mtr,   mtr+X,   1LL);
        fill(mtr+X, mtr+2001, 0LL);
        fill(vec+1, vec+N+1, 0LL);
        vec[0] = 1LL;
        for(;D; D /= 2){
            if(D & 1){
                for(int i = 0; i <= N; i++){
                    tmp[i] = 0LL;
                    for(int j = 0; j <= i; j++){
                        tmp[i] += mtr[i-j] * vec[j];
                        tmp[i] %= MOD;
                    }
                }
                for(int i = 0; i <= N; i++){
                    vec[i] = tmp[i];
                }
            }
            for(int i = 0; i <= N; i++){
                tmp[i] = 0LL;
                for(int j = 0; j <= i; j++){
                    tmp[i] += mtr[i-j] * mtr[j];
                    tmp[i] %= MOD;
                }
            }
            for(int i = 0; i <= N; i++){
                mtr[i] = tmp[i];
            }
        }
        cout << vec[N] << endl;
    }
    return 0;
}