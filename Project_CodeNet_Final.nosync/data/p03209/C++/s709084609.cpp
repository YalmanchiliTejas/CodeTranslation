#include<bits/stdc++.h>
using namespace std;
#define len(val) static_cast<long long>(val.size())
#define rep(i, n) for(int i=0; i<(n); i++)
typedef long long ll;

ll A[55];
ll P[55];

ll f(ll N, ll X){
    if(X == 1){
        if(N == 0){
            return 1;
        }else{
            return 0;
        }
    }
    else if((1 < X) and (X <= 1+A[N-1])){ return f(N-1, X-1);}
    else if(X == 2+A[N-1]){ return P[N-1]+1;}
    else if((2+A[N-1] < X) and (X <= 2+2*A[N-1])){ return P[N-1]+1+f(N-1, X-2-A[N-1]);}
    else if(3+2*A[N-1] == X){ return 2*P[N-1]+1;}
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, X;
    cin >> N >> X;
    rep(i, N){
        if(i == 0){
            A[i] = 1;
            P[i] = 1;
        }else{
            A[i] = 2*A[i-1]+3;
            P[i] = 2*P[i-1]+1;
        }
    }
    cout << f(N, X) << endl;

}
