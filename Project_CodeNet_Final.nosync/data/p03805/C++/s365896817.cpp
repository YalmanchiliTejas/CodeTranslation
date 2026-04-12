#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define ull         unsigned long long
#define pb          push_back
#define pii         pair<int,int>
#define pll         pair<long,long>
#define vi          vector<int>
#define vll         vector<ll>
#define vii         vector<pii>
#define Mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define ff           first
#define ss           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define mod        1000000007
//#define mod        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rem(i,a,b)  for(int i=a;i>b;i--)
#define mp(a,b)     make_pair(a,b)
#define INF         numeric_limits<ll>::max();
#define NINF        numeric_limits<ll>::min();
#define vvi(a,b,name)    vector<vector<double>> name(a,vector<double>(b,-1))
//const ld pi=3.14159265359;

inline ll add(ll a,ll b,ll m){
    if((a+b)>=m)return (a+b)%m;
    return a+b;
}
inline ll mul(ll a,ll b,ll m){
    if((a*b)<m)return a*b;
    return (a*b)%m;
}

void solve(){
    int n,m;cin>>n>>m;
    int mat[n+1][n+1];
    int a,b;
    rep(i,0,n+1){
        rep(j,0,n+1){
            mat[i][j]=0;
        }
    }
    rep(i,0,m){
        cin>>a>>b;
        mat[a][b]=1;
        mat[b][a]=1;

    }
    vector<int> v;
    rep(i,2,n+1){
        v.pb(i);
    }
    int path=0;
    do{
        int cnt=0;
        a=1;
        b=v[0];
        int i=0;
        while(i<v.size()){
            if(mat[a][b]==1)cnt++;
            else break;
            i++;
            a=b;
            b=v[i];
        }
        if(i==v.size())path++;

    }while(next_permutation(all(v)));
    cout<<path<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
