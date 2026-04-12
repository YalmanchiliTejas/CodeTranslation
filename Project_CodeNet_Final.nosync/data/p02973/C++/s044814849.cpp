#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    int n;cin>>n;
    vector<int>a(n);
    rep(i,n){
        int b;cin>>b;
        a[i]=-b;
    }
    vector<int>dp(n,inf);
    rep(i,n){
        *upper_bound(all(dp),a[i])=a[i];
    }
    cout<<lower_bound(all(dp),inf)-dp.begin()<<endl;
}