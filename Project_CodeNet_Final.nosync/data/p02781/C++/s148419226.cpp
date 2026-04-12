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



void solve(){  
    string s;
    int n,m;
    cin >> s >> m;
    n = s.size();
    vector<vector<vector<int>>> dp(101,vector<vector<int>>(2,vector<int>(11,0)));
    dp[0][0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<=m;k++){
                ll D = s[i]-'0';
                for(int d=0;d<=(j ? 9 : D) ;d++){
                    dp[i+1][j || d < D][k+(d!=0)] += dp[i][j][k];
                } 
            }
        }
    }
    int ans = dp[n][0][m] + dp[n][1][m];
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