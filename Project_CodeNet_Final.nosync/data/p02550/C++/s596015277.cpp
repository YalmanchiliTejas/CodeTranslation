#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,x,m;cin>>n>>x>>m;
    map<ll,ll> mp;
    ll tmp=1;
    vector<ll> t;t.push_back(0);
    ll buf3=0,buf4=0;
    while(true){
        if(mp[x]!=0){
            buf4=mp[x]-1;
            buf3=tmp-mp[x];
            break;
        }
        t.push_back(x);
        mp[x]=tmp;
        x=(x*x)%m;
        tmp++;
    }
    
    ll buf=(n-buf4)/buf3,buf2=(n-buf4)%buf3;
    rep(i,tmp-1)t[i+1]+=t[i];
    ll res=t[buf4];
    if(x==0){
        cout<<t[tmp-1]<<endl;
        return 0;
    }
    res+=buf*(t[tmp-1]-t[buf4]);
    if(buf2!=0)res+=(t[buf2+buf4]-t[buf4]);
    cout<<res<<endl;
}