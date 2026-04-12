#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<tuple>
#include<stdio.h>
#include<set>

using namespace std;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)

#define shosu setprecision(10)
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Q;
typedef pair<Q,ll> R;
ll longinf=1ll<<60;
int inf=1<<29;
//mleしなければぜんぶllでかく。
//↑はあんまり気にしなくていい。
const ll MOD = 1e9+7;
const int index = 2*1e5+1;

ll add(ll a,ll b){
      return ((a%MOD)+(b%MOD))%MOD;
}

ll mul(ll a,ll b){
      return ((a%MOD)*(b%MOD))%MOD;
}

ll power(ll a,ll b){
      if(b==0) return 1;
      else if(b%2==0){
            ll ret=power(a,b/2);
            return ((ret%MOD)*(ret%MOD))%MOD;
      }
      else return ((power(a,b-1)%MOD)*(a%MOD))%MOD;
}
ll dive(ll a,ll b){
      return ((a%MOD)*(power(b,MOD-2)%MOD))%MOD;
}

ll frac[index+1];
void calc(){ //main関数内にcalc();を入れること
      frac[0]=1;
      rep0(i,index){
            frac[i+1]=mul(frac[i],i+1);
      }
}

int main(){
      int n,m,k;
      cin>>n>>m>>k;
      ll ans=0;
      calc();
      rep0(i,n){
            ans+=mul( mul(mul(m,m),mul(i,n-i)) , dive( frac[m*n-2] , mul(frac[m*n-k],frac[k-2]) ) );
            ans%=MOD;
      }
      swap(n,m);
      rep0(i,n){
            ans+=mul( mul(mul(m,m),mul(i,n-i)) , dive( frac[m*n-2] , mul(frac[m*n-k],frac[k-2]) ) );
            ans%=MOD;
      }
      cout<<ans<<endl;
return 0;
}