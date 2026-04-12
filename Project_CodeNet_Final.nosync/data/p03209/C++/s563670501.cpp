#include<bits/stdc++.h>
using namespace std;

using lint = long long;

lint layers[51];
lint putties[51];

lint P(int N, lint X){
    if(N == 0) return 1;
    if(X == 0 || X == 1) return 0;
    if(layers[N-1] + 1 >= X){
        return P(N-1, X-1);
    }
    else if(layers[N-1] + 2 == X) return putties[N-1] + 1;
    else if(layers[N-1]*2 + 2 >= X){
        return P(N-1, X - layers[N-1] - 2) + putties[N-1] + 1;
    }
    else if(layers[N-1]*2 + 3 == X){
        return putties[N-1]*2 + 1;
    }
    else{
        return 99999999999999999999999999999999999999;
    }
}

int main(){
    int N;
    lint X;

    cin >> N >> X;
    layers[0] = 1;
    putties[0] = 1;
    for(int i=1;i<=N;i++){
        layers[i] = layers[i-1]*2 + 3;
        putties[i] = putties[i-1]*2 + 1;
    }
    cout << P(N, X) << endl;
    return 0;
}