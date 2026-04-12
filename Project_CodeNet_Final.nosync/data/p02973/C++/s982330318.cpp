#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    deque<int> d;
    rep(i,n){
        int p=lower_bound(all(d),a[i])-d.begin();
        if(p==0) d.push_front(a[i]);
        else d[p-1]=a[i];
    }
    int ans=d.size();
    cout<<ans<<endl;
}

