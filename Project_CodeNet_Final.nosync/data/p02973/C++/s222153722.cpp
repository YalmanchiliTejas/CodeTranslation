#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];

    deque<int> dq;
    int ans=1;
    dq.push_back(a[0]);
    for(int i=1;i<n;i++){
        int x=lower_bound(all(dq),a[i])-dq.begin();
        if(x==0){
            ans++;
            dq.push_front(a[i]);
        }
        else dq[x-1]=a[i];
        //cout<<x<<" "<<ans<<endl;
    }

    cout<<ans<<endl;
}