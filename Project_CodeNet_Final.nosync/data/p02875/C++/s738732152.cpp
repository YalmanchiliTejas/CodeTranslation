#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e7,ha=998244353;

inline int add(int x,int y){ x+=y; return x>=ha?x-ha:x;}
inline void ADD(int &x,int y){ x+=y; if(x>=ha) x-=ha;}

inline int ksm(int x,int y){
	int an=1;
	for(;y;y>>=1,x=x*(ll)x%ha) if(y&1) an=an*(ll)x%ha;
	return an;
}

int jc[N+5],ni[N+5],n,ans;

inline int C(int x,int y){ return x<y?0:jc[x]*(ll)ni[y]%ha*(ll)ni[x-y]%ha;}

inline void solve(){
	jc[0]=1; for(int i=1;i<=n;i++) jc[i]=jc[i-1]*(ll)i%ha;
	ni[n]=ksm(jc[n],ha-2);
	for(int i=n;i;i--) ni[i-1]=ni[i]*(ll)i%ha;
	
	for(int i=0,c=2;i*2<n;i++,c=add(c,c)) ADD(ans,c*(ll)C(n,i)%ha);
	
	ans=add(ha-ans,ksm(3,n));
}

int main(){
	cin>>n,solve(),cout<<ans<<endl;
	return 0;
}