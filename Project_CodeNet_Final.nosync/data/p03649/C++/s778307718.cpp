#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb emplace_back


signed main(){
    int n;
    cin>>n;
    vector<int> v(n);
    rep(i,n)cin>>v[i];
    
    int ans = 0;
    
    int buf = 0;
    priority_queue<int> pq;
    rep(i,n)pq.push(v[i]);
    
    while(pq.top()+buf>n-1){
        int t = pq.top();
        pq.pop();
        
        int div = max<ll>(0,(t+buf)/n);
        ans += div;
        buf+=div;
        pq.push(t-div*(n+1));
    }
    
    cout<<ans<<endl;
    
}