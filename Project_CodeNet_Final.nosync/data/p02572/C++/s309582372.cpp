#include <bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

const int MOD = 1000000007; // 10^9 + 7
struct mint{int x;mint(int x=0):x((x%MOD+MOD)%MOD){}
mint operator-()const{return mint(-x);}
mint& operator+=(const mint a){if((x+=a.x)>=MOD)x-=MOD;return*this;}
mint& operator-=(const mint a){if((x+=MOD-a.x)>=MOD)x-=MOD;return*this;}
mint& operator*=(const mint a){(x*=a.x)%=MOD;return*this;}
mint operator+(const mint a)const{return mint(*this)+=a;}
mint operator-(const mint a)const{return mint(*this)-=a;}
mint operator*(const mint a)const{return mint(*this)*=a;}
mint pow(int t)const{if(!t)return 1;mint a=pow(t>>1);a*=a;if(t&1)a*=*this;return a;}
mint inv()const{return pow(MOD-2);}
mint& operator/=(const mint a){return*this*=a.inv();}
mint operator/(const mint a)const{return mint(*this)/=a;}};
ostream& operator<<(ostream& os, const mint& a) {return os << a.x;}

/****************************** START ******************************/

signed main() {
  cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(12);
  
  int n;cin >> n;
  vector<int> a(n);
  rep(i,0,n) cin >> a.at(i);
  
  mint sum = 0,sqsum = 0; // intの代わりにmintを宣言
  
  rep(i,0,n){
    sum += a[i];
    sqsum += a[i]*a[i];
  }
  
  mint ans;
  ans = sum;
  ans *= sum;
  ans -= sqsum;
  ans /= 2;
  
  cout << ans << endl;
  
  return 0;
}