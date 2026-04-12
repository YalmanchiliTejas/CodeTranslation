#include <bits/stdc++.h>  // ver2.2.5
#define int long long
#define endl "\n"
#define ALL(v) (v).begin(),(v).end()
#define COUNT(a,i) upper_bound(ALL(a),i)-lower_bound(ALL(a),i)
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
#define itos to_string
#define stoi stoll
#define FI first
#define SE second
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define _ <<' '<<
#define sortr(v) sort(v,greater<>())
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define repreq(i,a,b) for(int i=a;i>=b;i--)
#define leng(n) (int)(log10(n)+1)
#define dem(a,b) ((a+b-1)/(b))
#define Vin(a) rep(iI,0,a.size())cin>>a[iI]
#define Vout(a) rep(lZ,0,a.size()-1)cout<<a[lZ]<<' ';cout<<a.back()<<endl
#define VVout(a) rep(lY,0,a.size()){Vout(a[lY]);}
#define VPout(a) rep(lX,0,a.size())cout<<a[lX].FI<<' '<<a[lX].SE<<endl
#define Verr(a) rep(iZ,0,a.size()-1)cerr<<a[iZ]<<' ';cerr<<a.back()<<endl
#define VVerr(a) rep(iY,0,a.size()){Verr(a[iY]);}
#define VPerr(a) rep(iX,0,a.size())cerr<<a[iX].FI<<' '<<a[iX].SE<<endl
#define INF 3000000000000000000  //  3.0*10^18(MAXの1/3くらい)
#define MAX LLONG_MAX
#define MOD 1000000007  //  10^9 + 7
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}  //  最大公約数gcd
int lcm(int a,int b){return a/gcd(a,b)*b;}  //  最小公倍数lcm
void press(auto &v){v.erase(unique(ALL(v)),v.end());}  //  圧縮
int mypow(int x, int n, int m){  //  累乗x^n(mod m)  O(log(n))
if(n==0)return 1;if(n%2==0)return mypow(x*x%m,n/2,m);else return x*mypow(x,n-1,m)%m;}

string s,now,ans;

void va(int I){
  if(now[I]=='x') now[I] = 'o';
  else now[I] = 'x';
  return;
}

signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  int n;
  cin >> n >> s;
  
  //	1回目
  
  ans = s;
  now = s;
  
  ans[0]='S',ans[1]='S';
  
  rep(i,2,n){
    if(now[i-1]=='o') ans[i]='S';
    else {
      ans[i]='W';
      va(i-1);
      va(i);
      va((i+1)%n);
    }
  }
  
  cerr << now _ ans << endl;
  if(count(ALL(now),'x')==0) {cout<<ans<<endl;return 0;}
  //	2回目
  
  ans = s;
  now = s;
  
  ans[0]='S',ans[1]='W';
  va(0);
  va(1);
  va(2);
  
  rep(i,2,n){
    if(now[i-1]=='o') ans[i]='S';
    else {
      ans[i]='W';
      va(i-1);
      va(i);
      va((i+1)%n);
    }
  }
  
  cerr << now _ ans << endl;
  if(count(ALL(now),'x')==0) {cout<<ans<<endl;return 0;}
  //	3回目
  
  ans = s;
  now = s;
  
  ans[0]='W',ans[1]='S';
  
  va(n-1);
  va(1);
  va(0);
  
  rep(i,2,n){
    if(now[i-1]=='o') ans[i]='S';
    else {
      ans[i]='W';
      va(i-1);
      va(i);
      va((i+1)%n);
    }
  }
  
  cerr << now _ ans << endl;
  if(count(ALL(now),'x')==0) {cout<<ans<<endl;return 0;}
  //	4回目
  
  ans = s;
  now = s;
  
  ans[0]='W',ans[1]='W';
  
  va(n-1);
  va(2);
  
  rep(i,2,n){
    if(now[i-1]=='o') ans[i]='S';
    else {
      ans[i]='W';
      va(i-1);
      va(i);
      va((i+1)%n);
    }
  }
  
  cerr << now _ ans << endl;
  if(count(ALL(now),'x')==0) {cout<<ans<<endl;return 0;}
  cout<<-1<<endl;
  return 0;
}