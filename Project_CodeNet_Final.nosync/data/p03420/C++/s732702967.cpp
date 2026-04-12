#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    ll m=max(k,1LL);
    for(ll b=k+1;b<=n;b++){
        for(ll j=0;;j+=b){
            if(j){
                if(j+k>n){
                    break;
                }else if(j+b-1>n){
                    ans+=(n-j-k+1);
                    break;
                }else{
                    ans+=b-k;
                }
            }else{
                if(j+m>n){
                    break;
                }else if(j+b-1>n){
                    ans+=(n-j-m+1);
                    break;
                }else{
                    ans+=b-m;
                }
            }
        }

    }
    cout << ans<<endl;
    return 0;
}
