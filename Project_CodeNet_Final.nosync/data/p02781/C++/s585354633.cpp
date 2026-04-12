#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pii pair<int,int>
#include <bits/stdc++.h>
#define pll pair<ll,ll>
#define vi vector<int>
#define ld long double
#define ll long long
#define sh short int
#define pb push_back
#define mid (l+r)/2
#define S second
#define F first
using namespace std;
const int inf = 1e9*2;
const int mod = 1e9+7;
ll k;
ll dp[109][9][9];
string s;
ll bt(ll id,ll cnt,ll flag){
    if(cnt > k) return 0;
    if(id == s.size()) return (cnt == k);
    ll &ret = dp[id][cnt][flag];
    if(ret != -1) return ret;
    int ID = s[id] - '0';
    ret = bt(id+1,cnt,(flag || ID));
    if(!ID && !flag) return ret;
    for(int i=1;i<ID;i++){
        ret += bt(id+1,cnt+1,1);
    }
    if(flag){
        for(int i=max(1,ID);i<=9;i++){
            ret += bt(id+1,cnt+1,1);
        }
    }
    else if(ID) ret += bt(id+1,cnt+1,0);
    return ret;
}
int main(){
    fast,cin>>s>>k;
    memset(dp,-1,sizeof(dp));
    cout<<bt(0,0,0)<<endl;
}
