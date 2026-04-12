#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define modulo 1000000007
#define mod 998244353
#define int long long int
using namespace std;
string s;
int P;
vector<vector<int>>data[2];
int dp(int ind,int rem,bool lim){
      if(ind==s.length()){
            if(rem==0)return 1;
            else return 0;
      }
      int cnt=0;
      if(lim){
            for(int i=0;i<s[ind]-'0';i++){
                  if(data[0][ind+1][(rem+i)%P]==-1)data[0][ind+1][(rem+i)%P]=dp(ind+1,(rem+i)%P,false);
                  cnt=(cnt+data[0][ind+1][(rem+i)%P])%modulo;
            }
            if(data[lim][ind+1][(rem+s[ind]-'0')%P]==-1)data[lim][ind+1][(rem+s[ind]-'0')%P]=dp(ind+1,(rem+s[ind]-'0')%P,true);
            cnt=(cnt+data[lim][ind+1][(rem+s[ind]-'0')%P])%modulo;
      }
      else{
            for(int i=0;i<=9;i++){
                  if(data[0][ind+1][(rem+i)%P]==-1)data[0][ind+1][(rem+i)%P]=dp(ind+1,(rem+i)%P,false);
                  cnt=(cnt+data[0][ind+1][(rem+i)%P])%modulo;
            }
      }
      return cnt;
}
int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
   //   freopen("q.gir","r",stdin);
   //   freopen("q.cik","w",stdout);
      cin>>s;
      cin>>P;
      data[0].resize(s.length()+1,vector<int>(P,-1));
      data[1].resize(s.length()+1,vector<int>(P,-1));
      cout<<(dp(0,0,true)-1+modulo)%modulo;
}
