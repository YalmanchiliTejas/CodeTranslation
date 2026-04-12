#include<bits/stdc++.h>
#define rep(n) for(int i=0;i<(n);i++)
#define rep1(n) for(int i=1;i<=(n);i++)
#define all(n) n.begin(),n.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define int ll
using namespace std;
using ll=long long;
using pii=pair<int,int>;
#define pb push_back
ll dp[10005][105];
const ll mod = 1000000007;

signed main(){
    dp[0][0] = 1;
    string s;
    int d;
    cin>>s;
    cin>>d;
    int siz = s.size();
//assert(siz<=7);
    for(int i=1;i<=siz;i++){
      for(int j=0;j<d;j++){
        for(int k=0;k<10;k++){
          int tmp = j-k;
          tmp = (tmp%d+d)%d;
          dp[i][j] += dp[i-1][tmp];
          dp[i][j] %= mod;
        }
      }
    }

        int nsiz = siz;
        int acu = 0;
        int idx = 0;
        ll ans = 0;
        nsiz--;
        while(nsiz>=0){
          for(int i=0;i<s[idx]-'0';i++){
            int tmp = -i-acu;
            tmp = (tmp%d+d)%d;
            //cout<<nsiz<<" "<<tmp<<'\n';
            ans += dp[nsiz][tmp];
            ans %= mod;
          }
          acu += s[idx]-'0';
          idx++;
          nsiz--;
        }



        if(acu%d==0)ans++;
        ans--;

        cout<<(ans+mod)%mod<<'\n';



}
