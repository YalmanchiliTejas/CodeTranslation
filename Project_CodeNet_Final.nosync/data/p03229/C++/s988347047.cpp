#include <bits/stdc++.h>  // ver2.2.0
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Pii pair<int,int>
#define VPii vector<Pii>
#define Tiii tuple<int,int,int>
#define PQi priority_queue<int>
#define PQir priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define Vout(a) rep(lZ,0,a.size()-1)cout<<a[lZ]<<", ";cout<<a.back()
#define VVout(a) rep(lY,0,a.size()){Vout(a[lY]);}
#define VPout(a) rep(lX,0,a.size())cout<<a[lX].FI<<' '<<a[lX].SE<<endl
#define INF 3000000000000000000  //  3.0 * 10^18 (MAXの1/3くらい)
#define MOD 1000000007  //  10^9 + 7
using namespace std;
 
int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm
void uniq(Vi &v){sort(ALL(v)); v.erase(unique(ALL(v)),v.end());}  //  uniqのやつ
 
int mypow(int x, int n, int m){  //  累乗x^n(mod m)  O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}



signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  int n;
  cin >> n;
  Vi a(n);
  Vin(a);
  sort(ALL(a));
  
  deque<int> b;
  rep(i,1,n-1) b.pb(a[i]);
  
  int ans = a.back()-a[0];
  int nowa=a.back(),nowb=a[0];
  
  int qw,er,ty,ui,fr,ba,maxx;
  
  rep(i,1,n-1){
    fr = b.front();
    ba = b.back();
    
    qw = abs(fr-nowa);
    er = abs(ba-nowa);
    ty = abs(fr-nowb);
    ui = abs(ba-nowb);
    maxx = max({qw,er,ty,ui});
    
    if(maxx==qw){
      ans += qw;
      nowa = fr;
      b.pop_front();
    }
    else if(maxx==er){
      ans += er;
      nowa = ba;
      b.pop_back();
    }
    else if(maxx==ty){
      ans += ty;
      nowb = fr;
      b.pop_front();
    }
    else if(maxx==ui){
      ans += ui;
      nowb = ba;
      b.pop_back();
    }
    
  }
  cout << ans << endl;
  return 0;
}