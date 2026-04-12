#include<bits/stdc++.h>
#define FOR(i,a,b) for(register int i=a;i<=b;i++)

using namespace std;

inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

int main(){
	
	//freopen("date.txt","r",stdin);
	//freopen("mine.txt","w",stdout);
	
	int n=read();
	int num[n+2];
	memset(num,0,sizeof(num));
	FOR(i,1,n){
		int a=read();
		num[i]+=a;
		num[n-(i-1)]+=a;
	}
	
//	int n=100000;
//	int num[100000];
//	memset(num,0,sizeof(num));
//	FOR(i,1,n){
//		num[i]=i;
//	}
	
	//FOR(i,1,n) cout<<num[i]<<" "; cout<<endl;
	
	long long Ans=0;
	
	FOR(k,1,n-1){
		if((n-1)%k==0) continue;
		long long nAns=0;
		for(int now=1;now+k<=n;now+=k){
			nAns+=num[now];
			Ans=max(Ans,nAns);
		}
	}
	
	FOR(k,1,n-1){
		if((n-1)%k!=0) continue;
		long long nAns=0;
		for(int now=1;now<=n/2;now+=k){
			nAns+=num[now];
			Ans=max(Ans,nAns);
		}
	}
	
	cout<<Ans;
		
	return 0;
}
