#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll binomial(int64_t N, int64_t K) {
  if(K < 0 || N < K) return 0;
  ll ret = 1;
  for(ll i = 1; i <= K; ++i) {
    ret *= N--;
    ret /= i;
  }
  return ret;
}

ll dfs(string t,int x){
  ll ret=0;
  int len=t.size();
  if(t.size()<x){
    return 0LL;
  }
  if(x==0 || t.size()==0)return 1;
  string temp="";
  rep(i,t.size()){
    if(i!=0)temp+=t[i];
  }  
  if(t[0]=='0'){
    return dfs(temp,x);
  }
  if(t.size()==1 && x==1){
    return (ll)(t[0]-'0');
  }
  ll te=1;
  rep(i,x)te*=9;
  ret+=te/9*binomial(len-1,x-1)*(t[0]-'0'-1);
  ret+=te*binomial(len-1,x);
  return ret+dfs(temp,x-1);
}

int main(){
  string s;
  cin >> s;
  int k;
  cin >> k;
  ll ans=1;
  rep(i,k)ans*=9;
  ll n=s.size();
  cout << dfs(s,k) << endl;
return 0;}