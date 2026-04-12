#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()




int main(){
    int n;
    ll x;
    cin>>n>>x;
    vector<ll> psum(n+1), len(n+1);
    psum[0]=1; len[0]=1;
    rep(i,n){
        psum[i+1]=2*psum[i]+1;
        len[i+1]=2*len[i]+3;
    }
    ll ans=0;
    while(x>0){
        if(n==0){
            if(x==1) ans++;
            x--;
        }
        else{
            if(x>(len[n-1]+1)){
                ans+=(psum[n-1]+1);
                x-=(len[n-1]+2);
                n--;
            }
            else if(x==(len[n-1]+1)){
                ans+=psum[n-1];
                x-=(len[n-1]+1);
                n--;
            }
            else{
                x--;
                n--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}