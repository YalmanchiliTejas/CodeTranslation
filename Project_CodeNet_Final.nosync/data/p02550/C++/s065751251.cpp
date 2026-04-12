#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
template<class T>bool chmax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

ll n,x,m;
map<int,int> visited;
ll S[100010];

void solve(){
    cin >> n >> x >> m;
    ll a=x;visited[x]=1;S[1]=a;
    int sta=-1,T;
    rep(i,n-1){
        a*=a;a%=m;
        //cout << a << endl;
        if(visited[a]){
            sta=i+2;
            T=i+2-visited[a];
            break;
        }
        visited[a]=i+2;
        S[i+2]=S[i+1]+a;
    }
    //cout << sta << " " << T << endl;
    if(sta==-1) cout << S[n] << endl;
    else{
        ll V=S[sta-1]-S[sta-1-T];//cout << V << endl;
        ll p=(n-sta+1)%T,q=(n-sta+1)/T;
        ll ans=0;
        ans+=S[sta-1];
        ans+=q*V;
        ans+=S[sta-T-1+p]-S[sta-T-1];
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}