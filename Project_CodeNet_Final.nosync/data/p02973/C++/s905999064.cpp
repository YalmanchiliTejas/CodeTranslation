#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000009
const long long INF = 1LL<<60;

int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    deque<ll> dq;
    rep(i,n){
        int p=lower_bound(all(dq),a[i])-dq.begin();
        if(p==0) dq.push_front(a[i]);
        else dq[p-1]=a[i];
    }

    cout<<dq.size()<<endl;
}