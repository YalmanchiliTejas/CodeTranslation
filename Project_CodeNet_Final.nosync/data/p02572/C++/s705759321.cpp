#include<bits/stdc++.h>
#define sz 100002
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define pi pair<int,int>
#define PQ priority_queue<double, vector<double>, greater<double> >q
#define _sort(v) sort(v.begin(),v.end())
#define MP map<ll int,ll int>mp
#define MEM(x) memset(x,0,sizeof(x))
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define VEC() vector<ll int>v
#define VEC(n) ll int x; vector<ll int>v;for(int i=0;i<n;i++){cin>>x;v.pb(x);}
#define TEST() int test;cin>>test; while(test--)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
//Upper_bound   auto x=upper_bound(v[a].begin(),v[a].end(),les);les=*x; if(x==v[a].end())break;
//ll int LCM(ll int a,ll int b) { ll int gcd=__gcd(a,b);ll int lcm=a*b/gcd;return lcm;}
//ll int bigmod(ll int b, ll int p, ll int m){if(p==0)return 1;if(p%2!=0) return b%m*fun(b,p-1,m)%m;if(p%2==0){ ll int res=fun(b,p/2,m);return (res%m*res%m)%m;}}
//ll mod_inverse(ll a, ll mod){return bigmod(a,mod-2,mod);}
//void seive() { prime[np++]=2;for(i=3; i<=sz; i+=2){if(mark[i]==0){ prime[np++]=i;for(j=i*i; j<=sz; j+=i) mark[j]=1; } }}
//string add(string s1,string s2) {string s;int j=s1.size()-1,c=0,m; for(int i=s2.size()-1; i>=0; i--) {if(j>=0)m=s2[i]-'0'+s1[j]-'0'+c;else m=s2[i]-'0'+c; if(m>9) { s+=m%10+'0';c=m/10; } else {  c=0;s+=m+'0'; }j--; } if(c!=0) {s+=c+'0'; }reverse(s.begin(),s.end());return s;}
//int pos;string mul(int n) {string s;for(int i=0; i<pos; i++) { s+="0"; }pos++;int c=0,m; for(int i=s1.size()-1; i>=0; i--) { m=(s1[i]-'0')*n+c;if(m>9) { s+=m%10+'0';c=m/10;} else { c=0; s+=m+'0';} }while(c!=0) { s+=c%10+'0';c=c/10;}    reverse(s.begin(),s.end());return s;}

int main()
{
    ll int n,mod=1e9+7,sum=0,x,res=0;
    cin>>n;
  vector<ll int>v;
  for(int i=0;i<n;i++)
  {
      cin>>x;
      sum+=x;
      v.pb(x);
  }
  for(int i=0;i<n-1;i++)
  {
      res%=mod;
      sum-=v[i];
      x=sum%mod;
      res+=x*v[i];
  }
  cout<<res%mod<<endl;

}
