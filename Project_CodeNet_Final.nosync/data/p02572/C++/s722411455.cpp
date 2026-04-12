#include<bits/stdc++.h>

using namespace std;
using ll = long long;

#define MOD 1000000007
template<int mod>
struct ModInt{
   int x;
   ModInt():x(0){}
   ModInt(long long y):x(y>=0?y%mod:(mod-(-y)%mod)%mod){}
   ModInt &operator+=(const ModInt &p){
	   if((x+=p.x)>=mod)x-=mod;
	   return *this;
   }
   ModInt &operator-=(const ModInt &p){
	   if((x+=mod-p.x)>=mod)x-=mod;
	   return *this;
   }
   ModInt &operator*=(const ModInt &p){
	   x=(int)(1LL*x*p.x%mod);
	   return *this;
   }
   ModInt &operator/=(const ModInt &p){
	   *this*=p.inverse();
	   return *this;
   }
   ModInt &operator^=(long long p){
	   ModInt res = 1;
	   for (; p; p >>= 1) {
		   if (p & 1) res *= *this;
		   *this *= *this;
	   }
	   return *this = res;
   }
   ModInt operator-()const{return ModInt(-x);}
   ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}
   ModInt operator-(const ModInt &p)const{return ModInt(*this)-=p;}
   ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}
   ModInt operator/(const ModInt &p)const{return ModInt(*this)/=p;}
   ModInt operator^(long long p)const{return ModInt(*this)^=p;}
   bool operator==(const ModInt &p)const{return x==p.x;}
   bool operator!=(const ModInt &p)const{return x!=p.x;}
   explicit operator int() const { return x; }
   ModInt operator=(const int p) {x = p; return ModInt(*this);}
   ModInt inverse()const{
	   int a=x,b=mod,u=1,v=0,t;
	   while(b>0){
		   t=a/b;
		   a-=t*b;
		   std::swap(a,b);
		   u-=t*v;
		   std::swap(u,v);
	   }
	   return ModInt(u);
   }
   friend std::ostream &operator<<(std::ostream &os,const ModInt<mod> &p){
	   return os<<p.x;
   }
   friend std::istream &operator>>(std::istream &is,ModInt<mod> &a){
	   long long x;
	   is>>x;
	   a=ModInt<mod>(x);
	   return (is);
   }
};
typedef ModInt<MOD> mint;



int main()
{
	int n; cin >> n;
	vector<mint> a(n);
	for(int i = 0; i < n; i++)cin >> a[i];
	mint sum = 0;
	mint ans = 0;
	for(int i = 0; i < n; i++) {
		ans += sum * a[i];
		sum += a[i];
	}
	cout << ans << endl;
}