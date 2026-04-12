#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
void tostr(ll x,string& res){while(x)res+=('0'+(x%10)),x/=10; reverse(ALL(res)); return;}
template<class T> inline bool chmax(T& a,T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a,T b){ if(a>b){a=b;return 1;}return 0; }
//template end

ll dp[110][10][5][2]={};

int main(){
   string s; cin>>s;
   int k; scanf("%d",&k);
   reverse(ALL(s)); dp[s.size()][0][0][0]=1;
   rrep(i,s.size(),0)rep(j,0,10)rep(cnt,0,k+1)rep(f,0,2)if(dp[i][j][cnt][f]!=0){
      rep(to,0,10){
         if(!f&&(s[i-1]-'0')<to)continue;
         bool g=f; if(i==1||(s[i-1]-'0')>to)g=1;
         dp[i-1][to][cnt+(to!=0)][g]+=dp[i][j][cnt][f];
      }
   }
   /*
   rep(i,0,s.size()){
      rep(j,0,10){
         rep(cnt,0,4){
            rep(f,0,2)cerr<<dp[i][j][cnt][f]<<" "; puts("");
         }
      }
   }
   */
   ll res=0;
   rep(j,0,10)res+=dp[0][j][k][1];
   printf("%lld\n",res);
   return 0;
}