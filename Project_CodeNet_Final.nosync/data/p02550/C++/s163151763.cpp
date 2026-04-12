#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007
const int N = 1e5 + 1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n , x, m;
    cin>>n>>x>>m;
    ll ans = 0;
    if(x == 1){
        cout<<n<<"\n";
        return 0;
    }else if(x == 0){
        cout<<"0\n";
        return 0;
    }
    set<ll> s;
    vector<ll> rem;
    ll sum = 0;   
    ll same = -1;
    while(1){
        ans += x;
        s.insert(x);
        rem.pb(x);
        n--;
        if(n == 0){
            break;
        }
        x *= x;
        x %= m;
        if(s.find(x) != s.end()){
            same = x;
            break;
        }
    }
    ll l = 0;
    bool ok = 0;
    for(auto it : rem){
        if(it == same){
            ok = 1;
        }
        if(ok){
            sum += it;
            l++;
        }
    }
    if(l != 0){
        ans += (n/l)*sum;
        n -= ((n/l)*l);
    }
    ok = 0;
    for(auto it : rem){
        if(it == same){
            ok = 1;
        }
        if(ok){
            if(n == 0){
                break;
            }
            ans += it;
            n--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}