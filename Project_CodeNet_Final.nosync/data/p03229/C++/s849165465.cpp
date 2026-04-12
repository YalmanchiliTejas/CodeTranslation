#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int t=1,b=n-1;
    ll l=a[0],r=a[0],ans1=0,ans2=0;
    while(1){
        if(t>b) break;
        ans1+=abs(a[b]-l);
        l=a[b];
        --b;
        if(t>b) break;
        ans1+=abs(a[b]-r);
        r=a[b];
        --b;
        if(t>b) break;
        ans1+=abs(a[t]-l);
        l=a[t];
        ++t;
        if(t>b) break;
        ans1+=abs(a[t]-r);
        r=a[t];
        ++t;
    }
    b=0,t=n-2;
    l=a[n-1],r=a[n-1];
    while(1){
        if(b>t) break;
        ans2+=abs(a[b]-l);
        l=a[b];
        ++b;
        if(b>t) break;
        ans2+=abs(a[b]-r);
        r=a[b];
        ++b;
        if(b>t) break;
        ans2+=abs(a[t]-l);
        l=a[t];
        --t;
        if(b>t) break;
        ans2+=abs(a[t]-r);
        r=a[t];
        --t;
    }
    cout << max(ans1,ans2) << "\n";
    return 0;
}   