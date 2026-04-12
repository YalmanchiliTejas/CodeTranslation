#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
using vvll = vector< vector<ll> >;
using vll = vector<ll> ;
using vb = vector<bool> ;
using pll = pair<ll, ll> ;

#define IOS ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define I insert
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((long long)x.size())
#define arr array

const ll maxs = 1e6+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e10;


void pre(){



}

string s;
int k,n;
int dp[105][105][2];
bool vis[105][105][2];

int go(int pos,int cnt,int flg){
    if(cnt > k)
        return 0;
    if(pos >= n){
        return cnt == k;
    }
    if(vis[pos][cnt][flg])
        return dp[pos][cnt][flg];
    vis[pos][cnt][flg] = true;
    int limit = 9;
    if(flg) limit = s[pos]-'0';
    int ans=0;
    for(int d=0;d<=limit;d++){
        int isNonZero = (d == 0) ? 0 : 1;
        if(flg and d == limit){
            ans += go(pos+1,cnt + isNonZero,1);
        }else{
            ans += go(pos+1,cnt + isNonZero,0);
        }
    }
    return dp[pos][cnt][flg] = ans;
}

void solve(){  

    cin >> s >> k;
    n = s.size();
    int ans = go(0,0,1);
    cout << ans << endl;

}   

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input00.txt","r",stdin);
    #endif
    IOS;
    pre();
    ll T = 1;   
    //cin>>T;
    ll tt = 1;
    while(T--){  
        //cout << "Case #" << tt << ": "; 
        tt++;
        solve();
    }
    return 0;
}