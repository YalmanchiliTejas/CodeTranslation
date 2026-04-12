#include "bits/stdc++.h"
#define MAXN 200009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
int fac[MAXN],inv[MAXN];
int mod(ll x){
	return (x%INF);	
}
int C(int x,int y){
	if(x<y)
		return 0;
	return mod(fac[x]*1LL*mod(inv[y]*1LL*inv[x-y]));			
}
int Fe(int x,int y){
	if(!y)
		return 1;
	int h=Fe(x,y/2);
	h=mod(h*1LL*h);
	if(y&1)
		h=mod(h*1LL*x);
	return h;			
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	inv[0]=fac[0]=1;
	for(int i=1;i<MAXN;i++){
		fac[i]=mod(fac[i-1]*1LL*i);
		inv[i]=Fe(fac[i],INF-2);	
	}
	printf("%d\n",mod(C(n*m-2,k-2)*1LL*mod(mod(m*1LL*m)*1LL*C(n+1,3)+mod(n*1LL*n)*1LL*C(m+1,3))));	
	return 0;
}
