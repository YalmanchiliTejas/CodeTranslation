#include <bits/stdc++.h>
#define int long long
#define ll long long
#define vl vector<ll>
#define pl pair<ll,ll>
#define mp make_pair
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) for(ll i=0;i<b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(),(v).end()
using namespace std;
ll n,k;
vl a,b;
signed main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        a.push_back(k);
        b.push_back(k);
    }
    sort(all(a));
    for(int i=0;i<n;i++){
        ll point=lower_bound(all(a),b.at(i))-a.begin();
        (point+1<=(n/2))?cout<<a.at(n/2)<<endl:cout<<a.at(n/2-1)<<endl;
    }
}