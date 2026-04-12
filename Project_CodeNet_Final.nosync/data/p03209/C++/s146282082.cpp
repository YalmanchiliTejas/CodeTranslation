#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rrep(i, n) for (ll i = n - 1; i >= 0; i--)
#define Rep(i, r, n) for (ll i = r; i < n; i++)
#define RRep(i, r, n) for (ll i = n - 1; i <= r; i--)
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define int long long
#define pb push_back
#define mp make_pair
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int MOD = (1000000007);
//const int MOD = (998244353);
//const int INF = (1 << 30)-1;
const int INF = (1LL << 60)-1;
const double EPS = (1 >> 30);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}

using Graph = vector<vector<pair<int, int>>>;
using Ki = vector<vector<int>>;
using Vi = vector<int>;

int bar[51];
int par[51];

int saiki(int n,int x,int ans){
    //debug(n);
    //debug(x);
    //debug(ans);
    //debug(bar[n]);
    //ans%=MOD;
    if(n==1){
        if(x==1) return ans;
        else if(x==2) return ans+1;
        else if(x==3) return ans+2;
        else if(x==4) return ans+3;
        else if(x==5) return ans+3;
    }
    if(x==1){
        return ans;
    }
    else if(x==bar[n]){
        ans+=2*par[n-1]+1;
        return ans;
    }
    else if(x==bar[n]/2+1){
        ans+=par[n-1]+1;
        return ans;
    }
    else if(x<bar[n]/2+1){
        x--;
    }
    else{
        ans+=par[n-1]+1;
        x-=bar[n]/2+1;
    }
    n--;
    return saiki(n,x,ans);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    //---------------------------------------------
    
    int n,x;
    cin>>n>>x;
    bar[0]=1;
    for(int i=1;i<=50;i++){
        bar[i]=1+bar[i-1]+1+bar[i-1]+1;
    }
    par[0]=1;
    for(int i=1;i<=50;i++){
        par[i]=par[i-1]*2+1;
    }
    int ans=0;
    int memo = saiki(n,x,ans);
    cout<<memo<<endl;
}
