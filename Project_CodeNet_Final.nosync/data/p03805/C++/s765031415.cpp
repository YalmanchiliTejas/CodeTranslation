#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
ll INF = 1e18;
void chmin(ll &a,ll b){if(a>b)a=b;}
void chmax(ll &a,ll b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x,ll y,ll z){if(x)cout<<y<<endl;else cout<<z<<endl;}
void anss(bool x,string y,string z){if(x)cout<<y<<endl;else cout<<z<<endl;}   
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}
ll n;
ll cnt=0;
vector<vector<ll>> a(8);//辺(添え字は始点、値は終点)
vector<ll>t(8);//訪問したかどうか
void dfs(ll k){
  t[k]=1;
  ll buf=0;
  for(ll i=0;i<a[k].size();i++){
    if(t[a[k][i]]==0){
      //cout<<k spa a[k][i]<<endl;
      dfs(a[k][i]); 
      buf++;
    }
  }
  if(buf==0){
    bool judge=true;
    for(ll i=0;i<n;i++){
      if(t[i]==0)judge=false;
    }
    if(judge)cnt++;
  }
  t[k]=0;
}

int main(){
  ll i,j,o;
  ll res=0,res1=0,res2=INF,buf=0,buf1=0,buf2=0,buf3=0,buf4=0,sum=0;
  ll l,r;
  bool judge = false;
  ll m;cin>>n>>m;
  ll p,q;
  for(i=0;i<m;i++){
    cin>>p>>q;
    a[p-1].push_back(q-1);
    a[q-1].push_back(p-1);
  }
  dfs(0);
  cout<<cnt<<endl;

  return 0;
}