#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
using namespace std;
const ll mod=1e9+7;
int main(){
    ll n,tmp=0,c=0,c2=0,x1=0,x2=0,ans=0;
    cin>>n;
    priority_queue<ll> q;
    rep(i,0,n){cin>>tmp;q.push(tmp);}
    bool p=true;
    while(p){
        c=q.top()+ans;
        x1=q.top();
        if(c<n){p=false;break;}
        else {
            ll sub =ceil(((ld)c-n+1)/n);
            ans+=sub;
            q.push(x1-sub*n-sub);
            q.pop();
        }
    }
    cout<<ans<<endl;
}
