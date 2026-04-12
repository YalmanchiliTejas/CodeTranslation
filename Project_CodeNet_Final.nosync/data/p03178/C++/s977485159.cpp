#include <bits/stdc++.h>
#define ff first
#define ss second
#define endl '\n'
using namespace std;
const long long INF = (long long) 1e18;
const int mod = (int) 1e9+7;
const int MAXN = (int) 1e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll D;
string K;
ll n;
ll dp[MAXN][105][2];
ll pw[MAXN];
bool done[MAXN][105][2];

ll d(ll ind, ll md, bool cnt){
    if(ind == n){
        if(md == 0) return 1;
        else return 0;
    }
    if(done[ind][md][cnt]){
        return dp[ind][md][cnt];
    }else{
        done[ind][md][cnt] = 1;
        if(cnt){
            ll mx = (int)(K[ind] - '0');
            for(int i = 0; i < mx; i++){
                dp[ind][md][cnt] += d(ind + 1, (md + i)%D, 0);
                dp[ind][md][cnt] %= mod;
            }
            dp[ind][md][cnt] += d(ind + 1, (md + mx)%D, 1);
            dp[ind][md][cnt] %= mod;
        }else{
            for(int i = 0; i < 10; i++){
                dp[ind][md][cnt] += d(ind + 1, (md + i)%D, 0);
                dp[ind][md][cnt] %= mod;
            }
        }
        return dp[ind][md][cnt];
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    #ifdef Local
        freopen("../IO/int.txt","r",stdin);
        freopen("../IO/out.txt","w",stdout);
    #endif

    cin>>K>>D;
    n = K.length();
    cout<<(d(0, 0, 1) - 1 + mod)%mod;
    

    #ifdef Local
        cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
    #endif
}