/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back

#define eb emplace_back
#define mod   1000000007
#define PI 2*acos(0.0)
#define all(r)(r).begin(),(r).end()
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define inf 1000000000000000000
#define N 2000
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};



//=============================================ASIFAZAD==============================================//

int32_t main()
{
    io;
    int n;
    cin>>n;
    vi inp(n);
    for(auto& x: inp) cin>>x;
    vi suf(n+1);
    for(int i = n-1; i >= 0; i--)
        suf[i] = (suf[i+1] + inp[i])%mod;
    ll ans = 0;
    for(int i = 0; i< n; i++)
        ans = (ans + 1LL*inp[i]*suf[i+1])%mod;
    cout<<ans;
    return 0;
}
