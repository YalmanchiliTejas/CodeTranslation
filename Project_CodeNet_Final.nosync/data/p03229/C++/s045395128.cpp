#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);
int main(){
    int n;cin>>n;
    vl a(n);
    rep(i,n)cin>>a[i];
    sort(been(a));
    ll ans =0;
    ll l =0,r=0;
    for(int i =1,j=n-1;i<=j;){
        ll li = abs(a[l]-a[i]);
        ll lj = abs(a[l]-a[j]);
        ll ri = abs(a[r]-a[i]);
        ll rj = abs(a[r]-a[j]);
        ll ma=max({li,lj,ri,rj});
        if(ma==li){
            l=i;
            i++;
        }
        else if(ma==lj){
            l=j;j--;
        }
        else if(ma==ri){
            r=i;i++;
        }
        else{
            r=j;j--;
        }
        ans+=ma;
    }
    cout<<ans<<endl;
}