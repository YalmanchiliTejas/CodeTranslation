#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N = 1e5+10;
ll n, m, x;
bool f[N];
void solve(){
    cin >> n >> x >> m;
    ll s = x;
    vector<ll>a;
    while(f[s]!=1) {
        a.push_back(s);
        f[s] = 1;
        s = (s * s)%m;
    }
    vector<ll>cycle;
    while(a.back() != s)
        cycle.push_back(a.back()), a.pop_back();
    if(a.size())
        a.pop_back();
    cycle.push_back(s);


    //for(int i:a)
        //cout << i << " ";
    //cout << "\n";
    //for(int i:cycle)
        //cout << i << " ";
    //cout << "\n";
    //return;


    reverse(cycle.begin(), cycle.end());


    if(n <= (int)a.size()) {
        ll ans = 0;
        for(int i=0;i<n;++i)
            ans += a[i];
        cout << ans << "\n";
        return;
    }
    n -= (int)a.size();
    ll rem = 0;
    for(int i=0;i<(n%(int)cycle.size());++i)
        rem += cycle[i];
    ll ans = accumulate(a.begin(), a.end(), 0LL) + (n/(int)cycle.size())*(accumulate(cycle.begin(), cycle.end(), 0LL)) + rem;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0; }

