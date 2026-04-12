#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define all(v) v.begin(),v.end()
using namespace std;

signed main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,n)cin>>a[i];
    int q;
    cin>>q;
    rep(i,q){
        int k;
        cin>>k;
        cout<<(lower_bound(all(a),k)-a.begin())<<endl;
    }
    return 0;
}
