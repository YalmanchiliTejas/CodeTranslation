#include <bits/stdc++.h> //AtCoder
#include <iostream> //Codeforces
#include <vector> //Codeforces

#define int long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repeq(i,a,b) for(int i=a;i<=b;i++)
#define Vi vector<int>
#define VVi vector<Vi>
#define Vs vector<string>
#define Vc vector<char>
#define cYES cout<<"YES"<<endl
#define cNO cout<<"NO"<<endl
#define cYes cout<<"Yes"<<endl
#define cNo cout<<"No"<<endl
#define cyes cout<<"yes"<<endl
#define cno cout<<"no"<<endl

using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}//最大公約数
int lcm(int a,int b){return a/gcd(a,b)*b;}//最小公倍数

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

signed main(){
  int N;
  cin >> N;
  Vi A(N);
  int mod = 1000000007;
  rep(i,0,N){
    cin >> A.at(i);
  }
    
  mint sum = 0;
  rep(i,0,N){
    sum += A.at(i);
  }
  mint sqsum = 0;
  rep(i,0,N){
    sqsum += A.at(i) * A.at(i);
  }
  
  cout << (sum * sum - sqsum) / 2;
}

