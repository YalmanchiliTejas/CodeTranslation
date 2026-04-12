#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 200010
#define int long long
#define mod 1000000007
#define debug cerr<<__LINE__<<" "<<__FUNCTION__<<"\n"

inline int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*y;
}
void put(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>=10) put(x/10);
    putchar((x%10)+48);
}
int n,m,A[N],B[N];
string s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();m=read();
	cin>>s;
	if(s[0]=='B'){
		for(int i=0;i<m;i++) s[i]=(s[i]=='B'?'R':'B');
	}
	int pos=s.find('B');
	if(pos==string::npos){
		A[1]=A[2]=1;
		for(int i=3;i<=n;i++) A[i]=(A[i-1]+A[i-2])%mod;
		cout<<(A[n]+2*A[n-1]%mod)%mod<<"\n";
		return 0;
	}
	if(n&1){
		puts("0");
		return 0;
	}
	int l=0x7ffffffff,res=0,flag=1;
	for(int i=0;i<m;i++){
		if(s[i]=='B'){
			if(flag||(res&1)) l=min(l,res+2);
			flag=0;
			res=0;
		}else res++;
	}
//	cerr<<l<<"\n";
	l/=2;n/=2;
	A[0]=B[0]=1;
	for(int i=1;i<=n;i++){
		A[i]=B[i-1];
		if(i>l) A[i]=(A[i]-B[i-l-1]+mod)%mod;
		B[i]=(B[i-1]+A[i])%mod;
	}
	int ans=0;
	for(int i=1;i<=l;i++){
		ans=(ans+2*i%mod*A[n-i]%mod)%mod;
	}
	cout<<ans<<"\n";
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
