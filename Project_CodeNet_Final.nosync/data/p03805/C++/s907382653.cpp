#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <cmath>
#include <complex> // complex<double> a(1.2 , 2.3);// real(): 1.2, imag()2.3
using namespace std;

#define MOD 1000000007
#define ll long long
#define ld long double
#define FOR(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define rmsame(a) sort(all(a)),a.erase(unique(all(a)), a.end())
#define rmvector(a,b) rep(i,a.size())rep(j,b.size())if(a[i]==b[j]){a.erase(a.begin()+i);i--;break;}
template<typename X> bool exist(vector<X> vec, X item){return find(all(vec), item)!=vec.end();}
ll gcd(ll a, ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}




int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll N , M ; cin >> N >> M ;
  map<ll, vector<ll> > E;
  rep(i,M){
    ll a, b; 
    cin >> a >> b;
    E[a].pb(b);
    E[b].pb(a);
  }
  
  vector<ll> lst;
  rep(i,N){
    lst.pb(i+1);
  }

  ll ans = 0;
  do{
    //開始が必ず1から
    if(lst[0] != 1 )continue;

    

    
    
    bool flag = true;
    rep(i,N-1){
      ll a = lst[i];
      ll b = lst[i+1];
      bool flag1 = false;
      rep(j,E[a].size()){
	if(E[a][j] == b) {flag1 = true; break;}
      }
      
      if(!flag1) {
	flag = false;
	break;
      }
    }
    if(flag) ans ++;
    
  }while(next_permutation(all(lst)));

  cout << ans << endl;
  
  //cout << fixed << setprecision(16) << ans << endl;
  return 0;
}
