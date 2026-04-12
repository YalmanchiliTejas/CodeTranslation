#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<int>vec;
set<int>S;
int main(){
    int n; cin >> n;
    rep(i,n){
        int a; cin >> a; vec.pb(a);
        for(int j=2;j*j<=a;j++){
            if(a%j!=0) continue;
            while(a%j == 0){
                a /= j;
            }
            S.insert(j);
        }
        if(a != 1) S.insert(a);
    }
    ll ans = 0;
    for(auto A:S){
        ll res = 0;
        rep(i,n) if(vec[i]%A==0)res+=vec[i];
        ans = max(ans,res);
    }
    cout << ans << endl;
}
