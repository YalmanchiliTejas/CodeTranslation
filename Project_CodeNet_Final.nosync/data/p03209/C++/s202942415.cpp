#include<bits/stdc++.h>
#define M 1000000007
#define pi ld(acos(-1.0))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,n) for(int i=1;i<(int)(n);i++)
#define repp(i,a,b)  for(ll i=a;i<=(ll)(b);i++)
#define Repp(i,a,b)  for(int i=a;i>=(int)(b);i--)
#define cs ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fi first
#define se second
#define ii pair<int,int>
#define bye(x) {cout<<x;return 0;}
typedef long long ll;
typedef long double ld;
using namespace std;
vector<ll> v(51);
vector<ll> vv(51);
ll solve(ll a,ll b) {
    if(a==0) return b>0?1:0;
    if(b<=1+v[a-1]) return solve(a-1,b-1); 
    return vv[a-1]+1+solve(a-1,b-v[a-1]-2);
}
void pre() {
    ll t=1,c=1;v[0]=1;vv[0]=1;
    repp(i,1,50) {
        t=t*2+3;
        c=c*2+1;
        v[i]=t;vv[i]=c;
    }
}
int main() {
    cs
    pre();
    ll n,q;
    cin>>n>>q;
    cout<<solve(n,q);

}