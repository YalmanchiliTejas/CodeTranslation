#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const long long INF = (long long) 1e18;
const int mod = (int) 1e9+7;
const int MAXN = (int) 3e3+5;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n;
ll arr[MAXN];
ll dp[MAXN][MAXN];
bool done[MAXN][MAXN];
ll d(int l, int r){
    if(l == r + 1){
        return 0;
    }
    if(done[l][r]) return dp[l][r];
    done[l][r] = 1;
    if(r == l){
        return dp[l][r] = arr[r];
    }else{
        ll ans1 = min(arr[l] - arr[r] + d(l + 1, r - 1), arr[l] - arr[l + 1] + d(l + 2, r));
        ll ans2 = min(arr[r] - arr[l] + d(l + 1, r - 1), arr[r] - arr[r - 1] + d(l, r - 2));
        return dp[l][r] = max(ans1, ans2);
    }
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    #ifdef Local
        freopen("../IO/int.txt","r",stdin);
        freopen("../IO/out.txt","w",stdout);
    #endif

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cout<<d(0, n - 1);
    #ifdef Local
        cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
    #endif
}