#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define per(i,a,b) for(int i=(a);i>=(int)(b);i--)
const int mod = 1e9+7;
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin>>n;
    ll ans=0,sum=0;
    rep(i,1,n) {
        ll x;
        cin>>x;
        ans=(ans+sum*x)%mod;
        sum=(sum+x)%mod;
    }
    cout<<ans<<'\n';
    return 0;
}
