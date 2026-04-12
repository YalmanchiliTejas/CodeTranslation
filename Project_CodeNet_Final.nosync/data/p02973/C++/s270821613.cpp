#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

int solve(int n,vector<ll> a){
    multiset<ll>s;
    rep(i,n){
        auto it=s.lower_bound(a[i]);
        if(it!=s.begin())s.erase(--it);
        s.insert(a[i]);
    }
    return s.size();
}
int main() {
ios::sync_with_stdio(false);
cin.tie(0);

int n;
cin>>n;
vector<ll>a(n);
rep(i,n)cin>>a[i];

cout<<solve(n,a)<<endl;
return 0;
}