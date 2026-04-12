#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int mod=1000000007;
char A[11000];
char B[11000];
char C[1100];
long long pow10[11000];
long long aval[11000];
long long bval[11000];
int main(){
	scanf("%s%s%s",B,A,C);
	pow10[0]=1;
	for(int i=1;i<11000;i++)pow10[i]=pow10[i-1]*10%mod;
	int a=strlen(A);
	int b=strlen(B);
	int c=strlen(C);
	long long r1=0;
	long long tmp=0;
	for(int i=0;i<a;i++){
		aval[i+1]=(aval[i]+pow10[i]*(A[a-1-i]-'0')%mod)%mod;
	}
	for(int i=0;i<b;i++){
		bval[i+1]=(bval[i]+pow10[i]*(B[b-1-i]-'0')%mod)%mod;
	}
	for(int i=0;i<a-c+1;i++){
		int ok=0;
		for(int j=0;j<c;j++){
			if(A[i+j]>C[j]){ok=1;break;}
			if(A[i+j]<C[j]){ok=-1;break;}
		}
		if(C[0]=='0')r1=(r1+mod-pow10[a-c-i])%mod;
		if(ok==1)r1=(r1+pow10[a-c-i])%mod;
		else if(~ok)r1=(r1+aval[a-c-i]+1)%mod;
		r1=(r1+pow10[a-c-i]*tmp)%mod;
		tmp=(tmp*10+A[i]-'0')%mod;
	//	printf("%lld\n",r1);
	}
	long long r2=0;
	tmp=0;
	for(int i=0;i<b-c+1;i++){
		int ok=0;
		for(int j=0;j<c;j++){
			if(B[i+j]>C[j]){ok=1;break;}
			if(B[i+j]<C[j]){ok=-1;break;}
		}
		if(C[0]=='0')r2=(r2+mod-pow10[b-c-i])%mod;
		if(ok==1)r2=(r2+pow10[b-c-i])%mod;
		else if(~ok)r2=(r2+bval[b-c-i]+1)%mod;
		r2=(r2+pow10[b-c-i]*tmp)%mod;
		tmp=(tmp*10+B[i]-'0')%mod;
	//	printf("%lld\n",r1);
	}
	long long r3=0;
	for(int i=0;i<b-c+1;i++){
		bool ok=true;
		for(int j=0;j<c;j++){
			if(B[i+j]!=C[j]){ok=false;break;}
		}
		if(ok)r3++;
	}
	printf("%lld\n",(r1+mod-r2+r3)%mod);
}