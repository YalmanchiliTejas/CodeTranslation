#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
typedef long long ll;
using namespace std;
const ll mod=1000000007,mod9=1000000009;
template <class T>inline T lcm(T a,T b){return (a*b/__gcd(a,b));}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    set<ll> s;
    map<ll,ll> mp;
    set<ll>::iterator itr;
    for(int i=0;i<n;i++){
        if(!s.empty()){
            itr=s.lower_bound(a[i]);
            if(itr==s.begin()){
                ans++;
                s.insert(a[i]);
                mp[a[i]]++;
            }
            else{
                itr--;
                mp[*itr]--;
                if(mp[*itr]==0){
                    s.erase(*itr);
                }
                s.insert(a[i]);
                mp[a[i]]++;
            }
        }
        else{
            ans++;
            s.insert(a[i]);
            mp[a[i]]++;
        }
    }
    cout << ans<<endl;
    return 0;
}

