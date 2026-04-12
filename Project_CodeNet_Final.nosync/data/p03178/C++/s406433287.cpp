#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1e9+7;
vector<ll> digits;
ll add_self(ll& a, ll b){
  a+=b;
  if(a>mod){
    a-=mod;
  }
}
ll dp[10001][101][2];
ll d;
void get_digits(string n){
  for(int i=n.size()-1;i>=0;i--){
    digits.push_back(n[i]-'0');
  }
}

ll foo(ll idx, ll sum, ll tight){
  if(idx==-1){
    if(sum==0){
      return 1;
    }
    else return 0;
  }
  if(dp[idx][sum][tight]!=-1){
    return dp[idx][sum][tight];
  }
  ll ans = 0;
  ll k = tight?digits[idx]:9;
  for(ll i=0;i<=k;i++){
    ll newTight = digits[idx]==i?tight:0;
    //ans+=foo(idx-1,(sum+i)%d,newTight);
    add_self(ans,foo(idx-1,(sum+i)%d,newTight));
  }
  dp[idx][sum][tight] = ans;
  return ans;
}

void init(){
  for(ll i=0;i<10001;i++){
    for(ll j=0;j<101;j++){
      for(ll k=0;k<2;k++){
        dp[i][j][k]=-1;
      }
    }
  }
}

int main(){
    string a;
    digits.clear();
    cin >> a  >> d;
    get_digits(a);
    ll sz = digits.size();
    init();
    ll ans1 = foo(sz-1,0,1);
    ans1--;
    if(ans1==-1){
      ans1 = -1+mod;
    }
    cout<<ans1<<endl;
}
