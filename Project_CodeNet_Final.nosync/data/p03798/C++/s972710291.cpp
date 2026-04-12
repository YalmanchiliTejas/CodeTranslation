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

int main(){
  ll i,j,o;
  ll res=0,res1=0,res2=INF,buf=0,buf1=0,buf2=0,buf3=0,buf4=0,sum=0;
  ll l,r;
  //bool judge = true;
  ll n;cin>>n;
  string s;cin>>s;
  vector<string> a(4);
  vector<bool> judge(4,false);
  a[0].push_back('S');
  a[0].push_back('S');
  a[1].push_back('S');
  a[1].push_back('W');
  a[2].push_back('W');
  a[2].push_back('S');
  a[3].push_back('W');
  a[3].push_back('W');
  for(j=0;j<4;j++){
  for(i=1;i<n-1;i++){
    if((s[i]=='o'&&a[j][i]=='S')||(s[i]=='x'&&a[j][i]=='W')){
      a[j].push_back(a[j][i-1]);
    }
    else a[j].push_back(a[j][i-1]=='S'?'W':'S');
  }
  if((s[n-1]=='o'&&a[j][n-2]==a[j][0]&&a[j][n-1]=='S')||
     (s[n-1]=='x'&&a[j][n-2]!=a[j][0]&&a[j][n-1]=='S')||
     (s[n-1]=='o'&&a[j][n-2]!=a[j][0]&&a[j][n-1]=='W')||
     (s[n-1]=='x'&&a[j][n-2]==a[j][0]&&a[j][n-1]=='W')
    )
  if((s[0]=='o'&&a[j][n-1]==a[j][1]&&a[j][0]=='S')||
     (s[0]=='x'&&a[j][n-1]!=a[j][1]&&a[j][0]=='S')||
     (s[0]=='o'&&a[j][n-1]!=a[j][1]&&a[j][0]=='W')||
     (s[0]=='x'&&a[j][n-1]==a[j][1]&&a[j][0]=='W')
    )
  judge[j]=true;
  }
  bool bufj=true;

  for(i=0;i<4;i++){
    if(judge[i]){
      bufj=false;
      cout<<a[i]<<endl;
      break;
    }
  }
  if(bufj)cout<<-1<<endl;

  //for(i=0;i<4;i++)cout<<a[i]<<endl;
    
  

  return 0;
}