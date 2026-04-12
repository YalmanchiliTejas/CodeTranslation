#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<map>

#define Rep(i,x,y) for (int i=x,_Lim=y;i<=_Lim;i++)
#define Dep(i,x,y) for (int i=x,_Lim=y;i>=_Lim;i--)

#define mk(a,b) make_pair(a,b)

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

int Stv[1<<8];

inline int read(){
	int f=1,res=0,ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=-1;ch=getchar();
	}
	while (ch>='0' && ch<='9') res=res*10+ch-48,ch=getchar();
	return f*res;
}

int n,m;
int main(){
	n=read(),m=read();
	if (m==0){
		cout<<1ll*n*n<<endl;return 0;
	}
	ll Ans=0;
	Rep(i,m+1,n){
		int kes=n/i;
		Ans+=1ll*(i-m)*kes;
		Ans+=max(n%i-m+1,0);
	}
	cout<<Ans<<endl;
}