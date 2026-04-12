#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;


int aa[200000],bb[200000],cc[2000000];
 
void t(){
  aa[0]=aa[1]=1;
  bb[0]=bb[1]=1;
  cc[1]=1;
  repi(i,2,200000){
    aa[i]=aa[i-1]*i%MOD;
    cc[i]=MOD-cc[MOD%i]*(MOD/i)%MOD;
    bb[i]=bb[i-1]*cc[i]%MOD;
  }
}
 
int calc(int n,int k){
  if(n<k) return 0;
  if(n<0 || k<0) return 0;
  return aa[n]*(bb[k]*bb[n-k]%MOD)%MOD;
}


int solve(string s,int k){
  if(k==0) return 1;
  if(s=="") return 0;
  int num=1;
  rep(i,k) num*=9;
  int ans=0;
  if(s[0]=='0') ans+=solve(s.substr(1),k);
  else{
    ans+=calc(s.size() - 1,k)*num;
    //cout<<s<<" "<<k<<" "<<ans<<endl;
    ans+=(int)(s[0]-'0'-1)*(calc(s.size() - 1,k-1))*(num/9);
    //cout<<s<<" "<<k<<" "<<ans<<endl;
    ans+=solve(s.substr(1),k-1);
    //cout<<s<<" "<<k<<" "<<ans<<endl;
  }
  return ans;
}

signed main(){
  cin.tie(0);	
  ios::sync_with_stdio(false);
  t();
  string a;
  int b;
  cin>>a>>b;
  cout<<solve(a,b)<<endl;
  

  return 0;
}
