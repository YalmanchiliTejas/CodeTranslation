#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<bitset>
#include<random>
#include<cstdint>
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
#define shosu setprecision(17)
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<char,P> Q;
ll longinf=(1ll<<60);
ll inf=1ll<<29;
int main(){
      ll n;
      cin>>n;
      ll x;
      cin>>x;
      ll bg[n];
      ll bn[n];
      ll pt[n];
      bn[0]=0;
      pt[0]=1;
      bg[0]=1;
      rep0(i,n){
            bn[i+1]=2*bn[i]+2;
            pt[i+1]=2*pt[i]+1;
            bg[i+1]=bn[i+1]+pt[i+1];
      }
      ll ans=0;
      ll now=(n-1);
      while(now>=-1){
            if(now==-1){
                  if(x>=1) ans++;
                  break;
            }
            if(x>=bg[now]+2){
                  x-=bg[now]+2;
                  ans+=pt[now]+1;
            }
            else x--;
            now--;
      }
      cout<<ans<<endl;
      return 0;
}