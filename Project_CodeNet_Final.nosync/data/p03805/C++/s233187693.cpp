#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (1<<29)
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
bool prime(int p){
	for(int i=2;i<=sqrt(p);i++){
		if(!p%i)return false;
	}
	return true;
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b==1)return a%MOD;
    if(b%2)return modpow(a,b-1)*a%MOD;
    else return modpow(a,b/2)*modpow(a,b/2)%MOD;
}
int comb(int a,int b){
    if(b==0||a==b)return 1;
    if(b==1)return a%MOD;
    return (comb(a-1,b-1)+comb(a-1,b))%MOD;
}
int n,m,a,b,x[9][9],o[8],ans=0;
signed main(){
    cin>>n>>m;
    rep(i,m){
        cin>>a>>b;
        x[a][b]=x[b][a]=1;
    }
    rep(i,n)o[i]=i+1;
    do{
        for(int i=1;i<n;i++){
            if(x[o[i-1]][o[i]]==0)goto bed;
        }
        ans++;
        bed:;
    }while(next_permutation(o+1,o+n));
    cout<<ans<<endl;
	return 0;
}