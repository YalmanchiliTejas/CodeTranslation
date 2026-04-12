
#include <iostream>
#include<vector>
using namespace std;
long long rev(long long a,long long def){
	long long pow=def-2;
	long long ans=1;
	long long mul=a;
	while(pow>0){
		if(pow&1){
			ans*=mul;
			if(ans>def)ans%=def;
		}
		mul*=mul;
		if(mul>def)mul%=def;
		pow>>=1;
	}
	return ans;
}

int main() {
	long long n,a,b,c,d;cin>>n>>a>>b>>c>>d;
	vector<vector<long long>> dp(n+1,vector<long long>(n+1,0)),ik(n+1,vector<long long>(n+1,1));
	vector<long long> ke(n+1),p(n+1),prev(n+1);
	long long def=1;
	for(int i=0;i<9;i++){
		def*=10;
	}
	def+=7;
	p[0]=1;
	ik[0][1]=1;
	ke[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*i;
		if(p[i]>=def)p[i]%=def;
		ke[i]=ke[i-1]*i;
		if(ke[i]>def)ke[i]%=def;
		ik[i][1]=ik[i-1][1]*i;
		if(ik[i][1]>def)ik[i][1]%=def;
		for(int j=2;j<=n;j++){
			ik[i][j]=ik[i][j-1]*ik[i][1];
			if(ik[i][j]>def)ik[i][j]%=def;
		}
	}
	for(int i=0;i<=n;i++){
		prev[i]=rev(p[i],def);
		ke[i]=rev(ke[i],def);
		for(int j=1;j<=n;j++){
			ik[i][j]=rev(ik[i][j],def);
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		if(i>=a){
		for(int j=0;j<=n;j++){
			long long k=c;
			while(k<=d){
				if(j-i*k<0)break;
				if(k==0){
					dp[i][j]+=dp[i-1][j-i*k];
				}else{
					long long add=1;
					add=dp[i-1][j-i*k]*p[n-j+i*k];
					if(add>def)add%=def;
					add*=prev[n-j];
					if(add>def)add%=def;
					add*=ik[i][k];
					if(add>def)add%=def;
					add*=ke[k];
					if(add>def)add%=def;
					dp[i][j]+=add;

				}
				if(dp[i][j]>def)dp[i][j]%=def;
				k++;
			}
			dp[i][j]+=dp[i-1][j];
			if(dp[i][j]>def)dp[i][j]%=def;
		}
		}else{
			dp[i][0]=1;
		}
	}
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=n;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	for(int i=0;i<=n;i++){
//		cout<<p[i]<<' ';
//	}
//	cout<<endl;
//	for(int i=0;i<=n;i++){
//		cout<<prev[i]<<' ';
//	}
//	cout<<endl;
	cout<<dp[b][n]<<endl;
	return 0;
}