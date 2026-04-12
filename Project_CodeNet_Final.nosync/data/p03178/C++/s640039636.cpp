#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;

int main(){
    string K;
    cin >> K;
    ll D;
    cin >> D;
    ll N=K.size();

    //dp1[i][j]は未満、i桁目まででjmodD;
    //dp0[i][j]は一致、i桁目まででjmodD;
    vector<vector<ll>> dp1(N, vector<ll>(D,0));
    vector<vector<ll>> dp0(N, vector<ll>(D,0));
    for(ll i=0;i<K[0]-'0';i++)dp1[0][i%D]++;
    dp0[0][(K[0]-'0')%D]=1;
    for(ll i=1;i<N;i++)
        for(ll j=0;j<D;j++){
            for(ll k=0;k<K[i]-'0';k++){
                dp1[i][(j+k)%D]+=dp1[i-1][j]+dp0[i-1][j];
                dp1[i][(j+k)%D]%=MOD;
            }
            dp1[i][(j+(K[i]-'0'))%D]+=dp1[i-1][j];dp1[i][(j+(K[i]-'0'))%D]%=MOD;
            dp0[i][(j+(K[i]-'0'))%D]+=dp0[i-1][j];dp0[i][(j+(K[i]-'0'))%D]%=MOD;
            for(ll k=(K[i]-'0')+1;k<10;k++){
                dp1[i][(j+k)%D]+=dp1[i-1][j];
                dp1[i][(j+k)%D]%=MOD;
            }
        }

    print((dp0[N-1][0]+dp1[N-1][0]-1+MOD)%MOD)
    


    return 0;
}
