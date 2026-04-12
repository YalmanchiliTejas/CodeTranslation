#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	char ch=0; x=0;
	bool sign=false;
	while(ch<'0'||'9'<ch) sign|=ch=='-',ch=getchar();
	while('0'<=ch&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=sign?-x:x;
}
int n;
int ary[3003];
long long dp[3003][3003];
int main(){
	read(n);
	for(int i=1;i<=n;++i){
		read(ary[i]);
	}
	for(int i=n;i>=1;--i){
		if(i&1){
			for(int j=1,e;j<=i;++j){
				e=n-i+j;
				dp[j][e]=max(dp[j+1][e]+ary[j],dp[j][e-1]+ary[e]);
			}
		} else {
			for(int j=1,e;j<=i;++j){
				e=n-i+j;
				dp[j][e]=min(dp[j+1][e]-ary[j],dp[j][e-1]-ary[e]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}