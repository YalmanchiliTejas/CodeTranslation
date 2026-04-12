#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;


template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
ll h,w;
vector<vector<char>> a;

ll dx[4]={-1,1,0,0};
ll dy[4]={0,0,-1,1};

bool dfs(ll i,ll j){
    if(i==-1 && j==-1) return false;
    if(a[i][j]=='.') return false;
    ll cnt=0;
    pll pos;
    pos.fi=-1;
    pos.se=-1;
    rep(k,4){
        ll nx=i+dx[k];
        ll ny=j+dy[k];
        
        if(0<=nx && nx<=h-1 && 0<=ny && ny<=w-1 && a[nx][ny]=='#'){
            if(dx[k]==-1 || dy[k]==-1){
                return false;
            }
            cnt++;
            pos.fi=nx;
            pos.se=ny;
        }
        
    }
    if(i==h-1 && j==w-1 && a[i][j]=='#') return true;
    if(cnt==2) return false;
    a[i][j]='.';
    return dfs(pos.fi,pos.se);
}

const ll INF=1e9+7;

int main(){
    
    cin >> h >> w;
    a=vector<vector<char>>(h,vector<char>(w));
    rep(i,h){
        rep(j,w){
            cin >> a[i][j];
        }
    }
    if(dfs(0LL,0LL)){
        cout << "Possible" << endl;
    }
    else{
        cout << "Impossible" << endl;
    }
    return 0;
}