#include <bits/stdc++.h>
using namespace std;
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X)
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto xXx:v)cerr<<xXx<<' ';cerr<<endl;
#define INF 1000000007
#define LINF 1000000000000000007
#define Yes(X) if(X){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define YES(X) if(X){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define ctoi(C) (C-'0')
typedef long long ll;
typedef long double ld;
long long dx[] = {1,0,-1,0};
long long dy[] = {0,1,0,-1};
long long dx8[] = {1,1,0,-1,-1,-1,0,1};
long long dy8[] = {0,1,1,1,0,-1,-1,-1};
long long dx9[] = {1,1,0,-1,-1,-1,0,1,0};

vector<ll> a;

ll memo[3000][3000][2];
bool checked[3000][3000][2];

ll dfs(ll front,ll back,bool first){
    if(front == back)return (first ? a[front] : -a[front]);
    if(checked[front][back][first])return memo[front][back][first];
    ll ans = 0;
    if(first){
        ans = max(a[front]+dfs(front+1,back,0),a[back]+dfs(front,back-1,0));
    }
    else{
        ans = min(dfs(front+1,back,1)-a[front],dfs(front,back-1,1)-a[back]);
    }
    checked[front][back][first] = 1;
    return memo[front][back][first] = ans;
}

signed main(){
    ll N;
    cin >> N;
    a.resize(N);
    FOR(i,0,N)cin >> a[i];
    cout << dfs(0,N-1,1) << endl;
}