#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
#define prtarr(n,len) {for(int i=0;i<len;i++) cout<<n[i]<<" ";}

using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
using namespace std;

int n;
vll lists;
int main() {
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cin>>n;
    vll dp(n,0);
    ll sum=0;
    for(int i=0;i<n;i++){
        ll sub;
        cin>>sub;
        sum+=sub;
        lists.pb(sub);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(i==0) dp[i]=sum;
        else dp[i]=(dp[i-1]-lists[i-1]);
    }
    for(int i=0;i<n-1;i++){
        ans+=((dp[i+1]%MOD)*lists[i])%MOD;
    }
    cout<<ans%MOD;
    return 0;
}


