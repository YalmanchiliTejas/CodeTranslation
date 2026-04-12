#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> l, p;

ll f(int N, ll X){
    ll ret = 0;
    if(N == 0) ret = 1;
    else if(X == 1) ret = 0;
    else if(1 < X && X <= l[N-1] + 1){
        ret = f(N-1,X-1);
    }else if(X == l[N-1] + 2){
        ret = p[N-1] + 1;
    }else if(l[N-1] + 2 < X){
        ret = p[N-1] + 1 + f(N-1, X-l[N-1]-2);
    }
    return ret;
}

int main(){
    int N;  ll X;
    cin >> N >> X;

    l = vector<ll>(N+1, 0);
    p = vector<ll>(N+1, 0);
    l[0] = 1;  p[0] = 1;
    for(int i=0; i<N; i++){
        l[i+1] = 2*l[i] + 3;
        p[i+1] = 2*p[i] + 1;
    }
    cout << f(N, X) << endl;
}
