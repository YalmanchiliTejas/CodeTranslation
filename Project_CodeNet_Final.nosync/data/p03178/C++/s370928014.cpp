#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e4+10;
const int mod = 1000000007;
using namespace std;

string K;
ll D,len;
ll f[maxn][105];

ll dfs(int pos,int sum,bool limit){
    if(!limit && f[pos][sum] != -1) return f[pos][sum];
    if(pos == len+1) return f[pos][sum] = sum == 0;
    int up = limit ? (K[pos] -'0') : 9;
    ll ans = 0;
    for(int i = 0;i<=up;i++){
        ans += dfs(pos+1,(sum+i)%D,limit && i == up);
        ans %= mod;
    }
    if(!limit) f[pos][sum] = ans;
    return ans;
}

int main(){
    // debug;
    ios;

    cin>>K>>D;
    len = K.length();
    K = '#'+K;
    memset(f,-1,sizeof f);
    cout<<(dfs(1,0,1) - 1 + mod) %mod<<'\n';
    return 0;
}
