#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb emplace_back
#define INF (1LL<<59)

#define int ll

signed main(){
    int n;
    cin>>n;
    vector<pii> v(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        v[i] = pii(a,b);
    }
    
    sort(all(v));
    int mini = v[0].first;
    int maxi = 0;
    rep(i,n)maxi = max<ll>(maxi,v[i].second);
    
    int ans = INF;
    
    multiset<int> ms1,ms2;
    rep(i,n){
        ms1.insert(v[i].first);
        ms2.insert(v[i].second);
    }
    
    int l1 = *(ms1.begin()), r1 = *(ms1.rbegin());
    int l2 = *(ms2.begin()), r2 = *(ms2.rbegin());
    ans = (r1-l1)*(r2-l2);
    
    
    rep(i,n-1){
        ms1.erase(ms1.find(v[i].first));
        ms1.insert(v[i].second);
        
        ms2.erase(ms2.find(v[i].second));
        ms2.insert(v[i].first);
        
        l1 = *(ms1.begin()), r1 = *(ms1.rbegin());
        l2 = *(ms2.begin()), r2 = *(ms2.rbegin());
        ans = min(ans,(r1-l1)*(r2-l2));
    }
    cout<<ans<<endl;
}