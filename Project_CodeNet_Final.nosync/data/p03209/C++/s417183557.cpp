#include <bits/stdc++.h>
#define chmin(a, b) ((a)=min((a), (b)))
#define chmax(a, b) ((a)=max((a), (b)))
#define fs first
#define sc second
#define eb emplace_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const ll MOD=1e9+7;
const ll INF=1e18;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

vector<ll> cntP(60, 0), l(60, 0);
ll ans;

ll solve(ll n, ll x){
    if(x==1) return (n==0?1:0);
    else if(1<x && x<=l[n-1]+1) return solve(n-1, x-1);
    else if(x==l[n-1]+2) return cntP[n-1]+1;
    else if(l[n-1]+2<x && x<=l[n-1]*2+2) return cntP[n-1]+1+solve(n-1, x-l[n-1]-2);
    else return cntP[n-1]*2+1;
}

int main(){
    ll n, x; cin>>n>>x;
    cntP[0]=1, l[0]=1;
    for(int i=1; i<=n; i++){
        cntP[i]=cntP[i-1]*2+1;
        l[i]=l[i-1]*2+3;
        //cout << cntP[i] << " " << l[i] << endl;
    }

    cout << solve(n, x) << endl;
}