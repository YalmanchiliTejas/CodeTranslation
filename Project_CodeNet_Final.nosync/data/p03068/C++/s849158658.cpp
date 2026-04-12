#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];

int main(){
    int N,K; string S;
    cin >> N >> S >> K;
    K--;
    rep(i,N){
        if(S[K]!=S[i]) S[i] = '*';
    }
    cout << S << endl;
}