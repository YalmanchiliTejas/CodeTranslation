#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = INF+7;
const ll LINF = 1e18;
#define rep(i,N) for(int (i)=0;(i)<(N);++(i))
#define rrep(i,N) for(int (i)=(N-1);(i)>0;--i)
#define FOR(i,j,N) for(int (i)=(j);(i)<(N);++(i))
#define put(n) cout<<(n)<<endl;
#define all(v) v.begin(),v.end()
#define MP make_pair
#define pb(n) push_back(n)
#define int long long

vector<int> B(1,1),P(1,1);
int f(int N,int X){
    int res = 0;
    if(N == 0) res += 1;
    else if(X == 1) res += 0;
    else if(X <= B[N-1]+1) res += f(N-1,X-1);
    else if(X == B[N-1]+2) res += P[N-1] + 1;
    else if(X <= 2*B[N-1]+2) res = P[N-1] + 1 + f(N-1,X-B[N-1]-2);
    else res += 2*P[N-1]+1;

    return res;
}

signed main(){
    ll N,X;
    cin >> N >> X;
    for(int i=0;i<=50;++i){
        B.emplace_back(B[i]*2 + 3);
        P.emplace_back(P[i]*2 + 1);
    }

    cout << f(N,X) << endl;
}