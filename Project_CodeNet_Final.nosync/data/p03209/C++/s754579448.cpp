#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

lint A[55], P[55];

lint rec(lint n, lint x){
    if(n==0){
        if(x<=0) return 0LL;
        return 1LL;
    }

    if(x <= 1 + A[n-1]) return rec(n-1, x-1);
    return P[n-1] + 1 + rec(n-1, min(A[n-1], x-A[n-1]-2)); 
}

int main(){
    lint n, x; cin >> n >> x;

    A[0] = P[0] = 1;
    for(int i=1;i<=n;i++){
        A[i] = 2 * A[i-1] + 3;
        P[i] = 2 * P[i-1] + 1;
    }

    cout << rec(n, x) << endl;
    return 0;
}