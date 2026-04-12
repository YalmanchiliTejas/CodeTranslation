#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007
#define INF 1000000000
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
int modpow(int a,int b){
    if(!b)return 1;
    if(b%2)return modpow(a,b-1)*a%MOD;
    return modpow(a,b/2)*modpow(a,b/2)%MOD;
}
int fac(int a){
    int Ans=1;
    for(int i=1;i<=a;i++){
        Ans*=i;
        Ans%=MOD;
    }
    return Ans;
}//kaijo
int comb(int a,int b){
    return fac(a)*modpow(fac(a-b),MOD-2)%MOD*modpow(fac(b),MOD-2)%MOD;
}
bool a[334],b[334];
int main(){
	int n,m;
	char c[334][334];	
	cin>>n>>m;
	rep(i,n){
		rep(j,m){
			cin>>c[i][j];
			if(c[i][j]=='#')a[i]=true,b[j]=true;
		}
	}
	rep(i,n){
		rep(j,m){
			if(a[i]&&b[j])cout<<c[i][j];
		}
		if(a[i]==true)cout<<endl;
	}
	
	return 0;
}
