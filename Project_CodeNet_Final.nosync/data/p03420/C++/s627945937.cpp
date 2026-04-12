#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
using namespace std; 

long long n,k,b,ans;

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin); 
#endif
	cin>>n>>k;
	for(b=k+1;b<=n;++b){
		ans+=(b-k)*(n/b)+((n%b)?max(0ll,n%b-k+(k!=0)):0);
	}
	printf("%lld\n",ans);
}
