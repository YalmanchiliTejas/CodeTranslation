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
    
    ll n,x,m;
    cin >> n >> x >> m;
    ll t=x,ans=0,sum=0,cnt=0;
    vector<ll> p;
    vector<int> id(m,-1);
    while(1){
        if(id[t]==0){
            break;
        }
        id[t]=0;
        ans+=t;
        --n;
        if(n==0){
            cout << ans << "\n";
            return 0;
        }
        p.push_back(t);
        t=(t*t)%m;
    }
    bool go=false;
    int s=0;
    for(auto u:p){
        if(u==t) go=true;
        if(go){
            ++cnt;
            sum+=u;
        }else{
            ++s;
        }
    }
    ans+=(n/cnt)*sum;
    int y=n%cnt;
    rep(i,y){
        ans+=p[i+s];
    }
    cout << ans << "\n";
    return 0;
}   