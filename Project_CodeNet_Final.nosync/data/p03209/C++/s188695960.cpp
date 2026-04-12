#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define inf (1ll<<60)
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl

using namespace std;

const int mod=1e9+7;

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

int f(int n,int x,vi &a,vi &p){
  if(n==0)return (x<=0)?0:1;
  if(x<=1)return 0;
  if(x<a[n-1]+2)return f(n-1,x-1,a,p);
  if(x==a[n-1]+2)return p[n-1]+1;
  if(x<2*a[n-1]+3)return p[n-1]+f(n-1,x-a[n-1]-2,a,p)+1;
  if(x==2*a[n-1]+3)return 2*p[n-1]+1;
  return 0;
}

void run(){
  int n,x;
  cin>>n>>x;
  vi a(n+1),p(n+1);
  a[0]=p[0]=1;
  rep(i,n){
    a[i+1]=2*a[i]+3;
    p[i+1]=2*p[i]+1;
  }
  cout<<f(n,x,a,p)<<endl;
}
