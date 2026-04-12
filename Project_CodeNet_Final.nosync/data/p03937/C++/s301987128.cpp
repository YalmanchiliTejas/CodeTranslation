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
#include<math.h>
using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
#define shosu setprecision(17)
#define hayai cin.tie(0);ios::sync_with_stdio(false);
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<char,P> Q;
ll longinf=(1ll<<60);
ll inf=1ll<<29;
ll mod=998244353;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin>>h>>w;
    char a[h][w];
    rep0(i,h)rep0(j,w) cin>>a[i][j];
    P now={0,0};
    a[0][0]='.';
    bool ok=true;
    while(1){
      if(now==(P){h-1,w-1}){
        a[h-1][w-1]='.';
        break;
      }
      int hei=now.first;
      int wed=now.second;
      if(hei+1<h&&a[hei+1][wed]=='#'){
        a[hei+1][wed]='.';
        now={hei+1,wed};
      }
      else if(wed+1<w&&a[hei][wed+1]=='#'){
        a[hei][wed+1]='.';
        now={hei,wed+1};
      }
      else{
        ok=false;
        break;
      }
      //cout<<now.first<<" "<<now.second<<endl;
    }
    if(ok){
      rep0(i,h){
        rep0(j,w){
          if(a[i][j]=='#') ok=false;
        }
      }
    }
    if(ok){
      cout<<"Possible"<<endl;
    }
    else{
      cout<<"Impossible"<<endl;
    }

      return 0;
}