#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n; cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];

    int ans=0;
    while(true){
        bool there=false;
        rep(i,n)if(a[i]>=n){
            int tmp=a[i]/n;
            a[i]-=tmp*n;
            ans+=tmp;
            there=true;
            rep(j,n)if(i!=j)a[j]+=tmp;
        }
        if(!there){
            cout<<ans<<endl;
            return 0;
        }
    }

}