#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
const ll mod = 1e9+7;
#define ALL(x) (x).begin(),(x).end()
#define pow(x,y) modpow(x,y)
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)

template <class T = int>T in(){
    T x;
    cin >> x;
    return (x);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int N = in(),K = in();
    ll answer = 0;
    for (int i = 1; i < N+1; i++){
        if(i < K){
            i = K;
            continue;
        }
        answer += (N/i)*(i-K);
        if(K == 0)answer-=1;
        answer += max(0,N%i - K + 1);
    }
    cout << answer << "\n";
}