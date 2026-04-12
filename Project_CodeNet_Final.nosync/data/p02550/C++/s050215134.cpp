#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long int ll;
#define int long long int
typedef vector<int> vi;
typedef pair<int, int> ii; typedef vector<ii> vii;
#define INF numeric_limits<ll>::max()
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
ll powmod(ll a,ll l, ll md){ll res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
ll binpow(ll a,ll l){ll res=1;while(l){if(l&1)res=res*a;l/=2;a=a*a;}return res;}
ll invmod(ll a, ll md){return powmod(a,md-2,md);}
const ll inf = 0xFFFFFFFFFFFFFFFL;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x, m;
    cin>>n>>x>>m;
    vi pos(m, -1);
    int val = x;
    vi arr_a(0);
    int left = 0;
    int right = m-1;
    for (int i=0; i<m; i++){
        if (pos[val] ==-1){
            pos[val] = i;
            arr_a.push_back(val);
            val = (val*val)%m;
        }
        else{
            left = pos[val];
            right = i-1;
            break;

        }
    }
    if (n-1 < left){
        int ans = 0;
        for (int i=0; i<n; i++){
            ans += arr_a[i];
        }
        cout<<ans<<"\n";

    }
    else{
        int q = (n-left)/(right- left +1);
        int r = (n-left)%(right- left +1);
        int sum1 = 0;
        int sum2 = 0;
        if (q>0){
            for (int i=left; i<=right; i++){
                sum1+= arr_a[i];
            }
        }
        for (int i=0; i<r+left; i++){
            sum2+= arr_a[i];
        }
        int ans = q*sum1 + sum2;
        cout<<ans<<"\n";

    }
    // for (auto x: arr_a){
    //     cout<<x<<" ";
    // }
    // cout<<"\n"<<left<<" "<<right<<"\n";
    return 0;
}
 