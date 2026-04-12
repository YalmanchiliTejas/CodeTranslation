#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    ll N,S;
    cin>>N>>S;
    vector<ll> v(N);
    rep(i,N) cin>>v[i];
    vector<ll> ans(3005,0);
    ll A = 0;
    for(int i = 0; i < N; i++){
        ans[0]++;
        for(int j = 3005; j >=0; j--){
            if(0<=j-v[i]){
                ans[j]=(ans[j]+ans[j-v[i]])%mod;
            }
        }
        A = (A+ans[S])%mod;
    }
    cout<<A<<endl;
}