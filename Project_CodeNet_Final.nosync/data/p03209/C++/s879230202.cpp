#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

ll p[51]={};
ll a[51]={};

ll saiki(ll N, ll X){
    if(N == 0){
        return ((X<=0)?0:1);
    }else{
        if(X <= ll(a[N]/2)){
            return saiki(N-1, X-1);
        }else if(X == ll(a[N]/2) +1){
            return p[N-1] + 1;
        }else{
            return p[N-1] + 1 + saiki(N-1, X-2-a[N-1]);
        }
        //pair<ll,ll> p = saiki(N-1);
        //return make_pair(p.first*2+1, p.second*2+2);
    }
}

int main(){
    ll N,X;
    cin >> N >> X;
    p[0] = 1;
    a[0] = 1;
    rep(i,N){
        p[i+1] = p[i]*2 + 1;
        a[i+1] = a[i]*2 + 3;
    }
    ll ans = saiki(N,X);

    cout << ans << endl;
}
/*
1 3 7
1 5 13
*/
//BBPPPB P BPPPBB