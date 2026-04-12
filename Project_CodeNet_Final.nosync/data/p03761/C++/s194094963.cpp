#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
ll MOD = 1e9+7;
//ll MOD = 998244353;
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

int main(){
  ll i,j,o;
  ll res=0,res1=0,res2=INF,buf=0,buf1=0,buf2=0,buf3=0,buf4=0,sum=0;
  ll l,r;
  bool judge = true;
  ll n;cin>>n;
  vector<string> s(n);
  for(i=0;i<n;i++)cin>>s[i];
  vector<ll> hash(26,INF);
  vector<ll> hashbuf(26,0);
  for(i=0;i<n;i++){
    fill(ALL(hashbuf),0);
    for(j=0;j<s[i].size();j++){
      hashbuf[s[i][j]-'a']++;
    }
    for(j=0;j<26;j++){
      chmin(hash[j],hashbuf[j]);
    }
  }
  for(i=0;i<26;i++){
    for(j=0;j<hash[i];j++)cout<<char('a'+i);
  }
  cout<<endl;
  
  
  return 0;
}