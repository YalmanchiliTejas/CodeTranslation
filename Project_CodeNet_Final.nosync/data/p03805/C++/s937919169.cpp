#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;
typedef pair<ll,ll> pairs;
typedef vector<pairs> p;


ll gcd(ll A,ll B){
    if (A%B==0)return(B);
    else return(gcd(B,A%B));
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

vector<vector<ll>> combination(ll n, ll r){
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
    for(ll i=0;i<v.size();++i){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for(ll i=1;i<v.size();++i){
        for(ll j=0;j<i;++j){
            v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]);
        }
    }
    return v;
}

bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

ll n, m;
ll ans = 0;
vector<ll> g[9];
bool x[9] = {true};

void search(ll p, ll q){
    if(q == n){
        ans++;
        return;
    }
    for(auto val : g[p]){
        if(!x[val]){
            x[val] = true;
            search(val, q+1);
            x[val] = false;
        }
    }
}

int main(){
    cin>>n>>m;
    for(ll i=0;i<m;++i){
        ll a, b;
        cin>>a>>b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    search(0, 1);
    cout<<ans<<endl;
    return 0;
}