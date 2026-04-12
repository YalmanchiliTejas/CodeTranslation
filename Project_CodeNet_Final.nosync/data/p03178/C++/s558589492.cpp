#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> 
#define pal pair < ll, ll> 
#define vi vector <int> 
#define vl vector < ll > 
#define vpai vector < pii > 

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 10001;

ll dp[sze][101][2];

ll calc(string str,int pos,int d,int tight,int sum){
    if(pos==(int)str.length()){
        if(sum==0) return 1;
        else return 0;
    }
    if(dp[pos][sum][tight]!=-1) return dp[pos][sum][tight];
    ll res=0;
    if(tight&1){
        for(int i=0;i<=str[pos]-'0';i++){
            if(i==str[pos]-'0'){
                res=(res+calc(str,pos+1,d,1,(sum+i)%d))%mod;
            }else res=(res+calc(str,pos+1,d,0,(sum+i)%d))%mod;
        }
    }else{
        for(int i=0;i<10;i++) res=(res+calc(str,pos+1,d,0,(sum+i)%d))%mod;
    }
    return dp[pos][sum][tight]=res;
}

void solve() {
    string str;
    cin>>str;
    int d;
    cin>>d;
    memset(dp,-1,sizeof(dp));
    
    cout<<(calc(str,0,d,1,0)-1+mod)%mod;
}

int main() {
    IOS;

    int t = 1;
    // cin >> t;
    while (t--) {
       solve();
    }

  return 0;
}