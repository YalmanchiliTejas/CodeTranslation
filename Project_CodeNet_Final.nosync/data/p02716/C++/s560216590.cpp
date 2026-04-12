#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }

/*
vector<ll> A(200010);
vector<ll> LS(200010,0);
vector<ll> RS(200010,0);
ll N;
ll dfs(ll i, ll sum , ll aff){
    if(aff > 0){
        return max(dfs(i+2, (sum+A[i]), aff), dfs(i+1, sum, (aff-1)));
    }else{
        if(i % 2 == 0){
            return sum + max(LS[N+1], LS[N])- LS[i+2] + A[i];
        }else{
            return sum + max(RS[N+1] ,RS[N]) - RS[i+2] + A[i];
        }
    }
}*/


int main(){
    ll N;
    string S;
    cin >> N;
    //ll LS=0;
    //ll RS=0;
    vector<ll> A(N);
    vector<vector<ll>> DP(N+1,vector<ll>(4,-1e18));
    rep(i,N){
        cin >> A[i];
    }
    ll K = 1 + (N%2);
    DP[0][0] = 0;
    rep(i,N){
        rep(j,K+1){
            cmax(DP[i+1][j+1], DP[i][j]);
            ll now = DP[i][j];
            if((i+j) % 2 == 0) now += A[i];
            cmax(DP[i+1][j], now); 
        }
    }
    cout << DP[N][K] << endl;
    /*
    ll sum = 0;
    rep(i,N){
        if(i%2 == 0){
            LS[i+2] += LS[i] + A[i];
        }else{
            RS[i+2] += RS[i] + A[i];
        }
    }
    cout << 1111 << endl;
    ll ans = 0;
    if(N % 2 == 0){
        ans = dfs(0,0,1);
    }else{
        ans = dfs(0,0,2);
    }
    cout << ans <<endl;
    */
}