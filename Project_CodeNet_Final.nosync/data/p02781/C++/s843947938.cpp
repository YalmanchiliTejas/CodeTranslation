#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll combination(ll n,ll r){
  if(n < r)return 0;
  ll ret = 1;
  ll divide = 1;
  for(ll i=0;i<r;i++){
    divide *= i+1;
    ret *= n-i;
  }
  return ret/divide;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;cin>>s;
  ll k;
  cin>>k;
  ll ans = 0;
  ll kake = 1;
  for(int i=0;i<k;i++){
    kake*=9;
  }
  ll hoge = 0;
  for(int i=0;i<s.size();i++){
    if(s[i] == '0'){
    }else{
      //    cout<<s.size()-1-i<<" "<<k-i<<endl;
      ans += combination(s.size()-1-i,k-hoge)*kake;
      //cout<<i<<" "<<ans<<endl;
      //cout<<s.size()-1-i<<" "<<k-i<<endl;
      ans += (s[i]-'0'-1)*combination(s.size()-1-i,k-hoge-1)*(kake/9);
      // cout<<i<<" "<<ans<<endl;
      hoge++;
      kake/=9;
    }
  }
  ll cnt=0;
  for(int i=0;i<s.size();i++)
    if(s[i] != '0')cnt++;
  if(cnt == k)ans++;
  cout<<ans<<endl;
  return 0;
}
