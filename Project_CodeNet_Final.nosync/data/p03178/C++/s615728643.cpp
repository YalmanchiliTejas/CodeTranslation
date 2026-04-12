#include <bits/stdc++.h>
#define int long long
using namespace std;

//educational DP contest S
template<int mod>
struct ModInt{
	int x;

	ModInt() : x(0){}
	ModInt(long long y) : x(y>=0 ? y%mod : (mod-(-y)%mod)){}

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

	ModInt operator-() const{return ModInt(-x);}
	ModInt operator+(const ModInt &p) const{return ModInt (*this)+=p;}
	ModInt operator-(const ModInt &p) const{return ModInt (*this)-=p;}
	ModInt operator*(const ModInt &p) const{return ModInt (*this)*=p;}
	ModInt operator/(const ModInt &p) const{return ModInt (*this)/=p;}
	bool operator==(const ModInt &p) const{return x==p.x;}
	bool operator!=(const ModInt &p) const{return x!=p.x;}
	friend ostream &operator<<(ostream &os, const ModInt &p){return os<<p.x;}
	friend istream &operator>>(istream &is,ModInt &a){
		int t;
		is>>t;
		a=ModInt<mod>(t);
		return (is);
	}

	ModInt inverse() const{
		int a=x, b=mod, u=1, v=0, t;
		while(b>0){
			t=a/b;
			a-=t*b;
			swap(a,b);
			u-=t*v;
			swap(u,v);
		}
		return ModInt(u);
	}
	
	ModInt pow(int e) const{
		long long a=1,p=x;
		while(e>0){
			if(e%2==0){p=(p*p)%mod; e/=2;}
			else {a=(a*p)%mod; e--;}
		}
		return ModInt(a);
	}
};
const int pri=1000000007;
ModInt<pri> dp[10000+1000][2][200];


signed main(){
	string S; int D; cin>>S>>D;
	dp[0][0][0]=1;
	int N=S.size();
	for(int i=0;i<N;i++){
		for(int smaller=0;smaller<2;smaller++){
			for(int j=0;j<=D;j++){
				for(int x=0;x<=(smaller ? 9 : S[i]-'0');x++){
					dp[i+1][smaller or x<(S[i]-'0')][(j+x)%D]+=dp[i][smaller][j];
				}
			}
		}
	}
	cout<<dp[N][0][0]+dp[N][1][0]-1<<endl;
}