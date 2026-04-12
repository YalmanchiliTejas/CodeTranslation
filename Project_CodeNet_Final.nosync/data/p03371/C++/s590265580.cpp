#include <bits/stdc++.h>
using namespace std;

#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384


int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;} 
int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}    //最大公約数
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}     //最小公倍数
int nCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;} //コンビネーション
int nHr(int a,int b){return nCr(a+b-1,b);}       // 重複組み合わせ
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}  //階乗
int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;} // a~bまでの階乗
int dsum(int x){int r=0;while(x){r+=(x%10);x/=10;}return r;}   //数字の各位の和
int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}  // b進数の各位の和？
int sankaku(int x){return ((1+x)*x)/2;} //三角数 xまでの和

//以下long long ver
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llnHr(long long a,long long b){return llnCr(a+b-1,b);}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long lldsum(long long x){long long r=0;while(x){r+=(x%10);x/=10;}return r;}
long long lldsumb(long long x,long long b){long long r=0;while(x){r+=(x%b);x/=b;}return r;}
long long llsankaku(long long x){return ((1+x)*x)/2;}

//double
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}


typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define forr(i,a,b) ; for(int i=(a); i<(b); i++)
#define clean(arr,val) memset(arr,val,sizeof(arr))
#define forn(i,n) forr(i,0,n)
#define PB push_back
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pll> vpll;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
bool is_prime (int x){
  if (x<=1) return false ;
  for (int i=2 ; i*i<=x ; i++){
    if (x%i==0) return false ;
  }
   return true;
}
string alpha = "abcdefghijklmnopqrstuvwxyz" ;
string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    
bool chmin (int a,int b){
    if ( a > b ){
    a = b;
    return true ;
    }
    return false ;
}
 bool chmax (int a,int b){
    if ( a < b ){
    a = b;
    return true ;
    }
    return false ;
}   
    
 
/*CODE START HERE*/
int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y ;
  long long ans = 1000100000;
 forn(i,100001){
   long long cost = 2*i*c+max(0,x-i)*a+max(0,y-i)*b;
   ans = llmin ( ans , cost) ;
 }
  cout << ans << endl;
}