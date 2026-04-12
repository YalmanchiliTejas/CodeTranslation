#include<bits/stdc++.h>
using namespace std;

// for loop
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define repe(i,a,n) for(int i=(a);i<=(n);++i)
#define rrep(i,n,a) for(int i=(n);n>(a);--i)
#define rrepe(i,n,a) for(int i=(n);n>=(a);--i)

// abbreviati
#define PB(v) push_back(v)
#define MP make_pair
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define ENDL << "\n"

using ll = long long;
using P = pair<int,int>;
using itn = int;

// constant
const int INF = 1<<30;
const ll INFLL = 1LL << 60;
const ll MOD = 1000000000+7;
const long double PI =(acos(-1));

/***Snippet***************************************************
ifelse, isprime, torad, todeg, lcm, bfs,chmin,chmax
**************************************************************/

// adjacency list
vector<int> to[100005];

// Graph
using Graph = vector<vector<int>>;

// Grid
int H,W;
vector<vector<int>> field;

// 4方向への移動ベクトル
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> A(n);
    vector<ll> sum(n);
    ll sums=0;
    //vector<ll> modn(MOD);
    rep(i,0,n){
        ll a=0;
        cin >> a;
        if(a>=MOD){
            A[i]=a%MOD;
        }else A[i]=a;
        //modn[A[i]]++;
        sums+=A[i];
    }
    rep(i,0,n){
        if(i==0)sum[i]=sums-A[i];
        else sum[i]=sum[i-1]-A[i];
    }

    // rep(i,0,n){
    //     cout << "sum: " << sum[i] ENDL;
    // }
    ll ans=0;
    rep(i,0,n){
        ans+=A[i]*(sum[i]%MOD);
        if(ans>=MOD) ans%=MOD;
    }
    // rep(i,0,n-1){
    //     rep(j,i+1,n){
    //         ans+=A[i] * A[j];
    //         if(ans>MOD) ans%=MOD;
    //         //cout << ans ENDL;
    //     }
        
    //     //cout << ans ENDL;
    // }
    // rep(i,0,n){
    //     rep(j,0,MOD){
            
    //         modn[A[i]]--;
    //         ans+=A.at(i)*A.at(j)*modn.at(A.at(j));
    //         if(ans>=MOD) ans%=MOD;
    //     }
    // }
    
    cout << ans ENDL;
    return 0;
}