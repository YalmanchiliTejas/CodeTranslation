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
//end

int n,dp[19][1<<18]; string s;

int main(){
   cin>>n>>s; int m=1<<n;
   rep(i,0,m)scanf("%d",&dp[0][i]);
   rep(i,0,n){
      int len=1<<i;
      rep(j,0,m){
         int x=dp[i][j],y=dp[i][(j+len)%m];
         if(x>y)swap(x,y);
         if(s[y-x-1]=='0')dp[i+1][j]=x; else dp[i+1][j]=y;
      }
   }
   rep(i,0,m)printf("%d\n",dp[n][i]);
   return 0;
}
