#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 998244353

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

int main(){
    ll n,x,m,ans=0;
    cin >> n >> x >> m;
    vector<ll> vec(m,-1);
    vector<ll> a;
    
    ll now=x;
    
    for(ll i=0;i<n;i++){
        if(i==0){
            vec[x]=i;
            ans+=x;
            a.push_back(x);
            continue;
        }
        now=(now*now)%m;
        if(vec[now]!=-1){
            ll haba=i-vec[now];
            ll total=0;
            for(ll j=vec[now];j<i;j++){
                total+=a[j];
            }
            ll kaisu=(n-i)/haba;
            ans+=kaisu*total;
            ll nokori=(n-i)%haba;
            for(ll j=vec[now];j<vec[now]+nokori;j++){
                ans+=a[j];
            }
            break;
        }else{
            vec[now]=i;
            ans+=now;
            a.push_back(now);
            continue;
        }
    }
    
    cout << ans << endl;

    return 0;
}









