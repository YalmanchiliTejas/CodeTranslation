
/*
██████╗  ███████╗  
██╔══██╗ ██╔════╝ 
██████╔╝ ███████╗ 
██╔══██╗ ╚════██║  
██║  ██║ ███████║      
╚═╝  ╚═╝ ╚══════╝                                                                                                             
*/

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define haha(j,a,n) for(int j=a;j<n;j++)
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define endl "\n"
#define bc(v) v.begin(),v.end()
#define vl vector<ll>
#define vi vector<int>
#define why 1000000007
#define NUM 100005
#define F first
#define S second
#define bhar(a) rep(i,a.size()) cin>>a[i];
#define show(a) rep(i,a.size()) cout<<a[i]<<" ";
#define sott(a) sort(bc(a))
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define mapp map<ll,ll>
#define dkac cout<<fixed<<setprecision(15);
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define yeah(n) while(n--)
ll gcd(int a, int b){if(b==0) return a; else return gcd(b,a%b);}
ll bitfun(ll x){
  return (x&(-x));
}
void solve(){
  string s; cin>>s;
  map<char,bool> ma;
  rep(i,3) ma[s[i]]=true; 
  ll cnt=0;
  for(auto j:ma) if(j.S) cnt++;
  if(cnt==2) cout<<"Yes";
  else cout<<"No";
}
int main(){
    ios
    int t=1; 
    //cin>>t;
    yeah(t){
      solve();
    }
}