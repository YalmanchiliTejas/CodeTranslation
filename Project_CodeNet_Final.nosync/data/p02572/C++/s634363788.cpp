#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
#define zero(v) memset(v,0,sizeof(v))
#define rep(i,n) for(int i=0;i<(n);i++)
#define foreach(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define all(v) (v).begin(),(v).end()
template<typename T>inline bool chkmin(T &a,const T &b){return a>b?a=b,1:0;}
template<typename T>inline bool chkmax(T &a,const T &b){return a<b?a=b,1:0;}
typedef long long ll;
typedef unsigned uint;
const int INF=0x3f3f3f3f;
const double EPS=1e-10;
typedef pair<int,int> pii;
int inline in(){int x=0,c;for(;(uint)((c=getchar())-'0')>=10;)
{if(c=='-')return -in();if(!~c)throw ~0;}do{x=(x<<3)+(x<<1)+(c-'0');}
while((uint)((c=getchar())-'0')<10);return x;}
int n;
const int Maxn=2e5+5;
const int mod=1e9+7;
int a[Maxn];

int main(){
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum=((ll)sum+a[i])%mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		sum=(((ll)sum-a[i])%mod+mod)%mod;
		ans=((ll)ans+(ll)a[i]*sum%mod)%mod;
	}
	cout<<ans%mod<<endl;
	return 0;
}