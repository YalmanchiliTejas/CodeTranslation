#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> nLayer;
vector<ll> nPatty;

ll calc(int N, ll X){
    ll ret = 0;
    if(X == 0) ret = 0;
    else if(X == 1){ 
        if(N == 0) ret = 1;
        else ret = 0;
    }
    else if(1 < X && X <= nLayer[N-1] + 1){
        ret = calc(N-1,X-1);
    }else if(X == nLayer[N-1] + 2){
        ret = nPatty[N-1] + 1;
    }else if(nLayer[N-1] + 2 < X && X <= 2*nLayer[N-1] + 2){
        ret = nPatty[N-1] + 1 + calc(N - 1, X - nLayer[N-1] - 2);
    }else{
        ret = 2*nPatty[N-1] + 1;
    }
    return ret;
}

int main(){
    int N;  ll X;
    cin >> N >> X;

    nLayer = vector<ll>(N+1, 0);
    nPatty = vector<ll>(N+1, 0);
    nLayer[0] = 1;  nPatty[0] = 1;
    for(int i=0; i<N; i++){
        nLayer[i+1] = 2*nLayer[i] + 3;
        nPatty[i+1] = 2*nPatty[i] + 1;
    }
    cout << calc(N, X) << endl;
}
