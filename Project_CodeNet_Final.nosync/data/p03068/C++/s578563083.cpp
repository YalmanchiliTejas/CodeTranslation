#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define repr(i,n) for(int i=(n);i>=0;--i)
#define int long long
#define itn int
#define pb push_back
#define m_p make_pair
#define m_t meke_tuple
#define p_p(a,b) pb(m_p(a,b))
#define all(a) a.begin(),a.end()
#define SORT(a) sort(all(a))
#define RSORT(a) sort(all(a));reverse(all(a))
#define UNIQUE(a) a.erase(unique(all(a)),a.end())
#define debg(a) cout<<#a<<" "<<a<<endl;
#define call(a) for(auto i:a)cout<<i<<" ";cout<<endl
#define out(a) cout<<(a)<<endl
#define fi first
#define se second
#define Vec vector
#define P pair
typedef long long ll;
typedef string str;
typedef vector<ll> V;
typedef pair<ll,ll> Pi;
typedef vector<Pi> VP;
const long long INF = 1LL<<60;
const long long MOD = 1e9+7;
int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int max(int a,int b){if(a>b)return a; return b;}
int min(int a,int b){if(a>b)return b; return a;}
void Yes(){cout<<"Yes"<<endl;}
void No(){cout<<"No"<<endl;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n,k;
  str s;
  cin>>n>>s>>k;
  char t=s[k-1];
  str a=s;
  rep(i,n){
    if(a[i]!=t)a[i]='*';
  }
  out(a);
  
  
  
  return 0;
}

