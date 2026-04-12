#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
ll dx[4]={0,1,-1,0};
ll dy[4]={1,0,0,-1};



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    ll n,x,mod;
    cin>>n>>x>>mod;
    ll ans = 0;
    ll cnt[mod+1]={};
    ll now = 1;
    while(!cnt[x] && n){
        n--;
        cnt[x] = now;
        now++;
        ans += x;
        x = (x*x)%mod;
    }
    if(n==0){
        cout << ans << endl;
        return 0;
    }
    ll c = now - cnt[x];
    ll d = 0;
    for(ll i=0;i<=mod;i++){
        if(cnt[i] >= cnt[x])d += i;
    }
    ll t = n/c;
    ans += t * d;
    ll rem = n % c;
    while(rem){
        rem--;
        ans += x;
        x = (x*x)%mod;
    }
    cout << ans << endl;

}