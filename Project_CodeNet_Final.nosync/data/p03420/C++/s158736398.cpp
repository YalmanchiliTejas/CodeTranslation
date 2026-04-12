#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n,k;
  cin >> n >> k;
  ll a,b;
  ll cnt=0;
  FOR(b,k+1,n+1){
    cnt +=n/b*(b-k)+max((ll)0,n%b-k+1);
    if(k==0){
      cnt--;
    }
  }
  cout << cnt << endl;
}