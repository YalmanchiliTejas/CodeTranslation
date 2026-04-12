#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
#define LINF 1e18
typedef long long ll;


int main() {
    ll N,X,M; cin >> N >> X >> M;

    ll a = X;

    ll cnt = 0;

    vector<ll> A(M,-1);
    vector<ll> num;
    A[a] = 0;
    num.push_back(a);
    FOR(i,1,M){
        a = a*a%M;
        if(A[a] == -1){
            A[a] = i;
            num.push_back(a);
        }else{
            cnt = A[a];
            break;
        }
    }

    int len = num.size();
    vector<ll> sum(len+1,0);
    
    REP(i,len){
        sum[i+1] += num[i] + sum[i];
    }

    
    ll loop = sum[len] - sum[cnt];

    if(N <= cnt){
        cout << sum[N] << endl;
    }else{
        cout << ((N-cnt)/(len-cnt))*loop + sum[cnt+(N-cnt)%(len-cnt)] << endl;
    }
    return 0;
}