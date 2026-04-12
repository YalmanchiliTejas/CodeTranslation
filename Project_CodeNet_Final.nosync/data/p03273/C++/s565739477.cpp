#include<bits/stdc++.h>

using namespace std;

inline int read(){
	char ch=getchar();int x=0,f=1;
    while(ch<'0' || ch>'9') {
       if(ch=='-') f=-1;
	  	  ch=getchar();
	}
    while(ch<='9' && ch>='0') {
	   x=x*10+ch-'0';
	   ch=getchar();
	}
    return x*f;
}

int h[1001],l[1010];

char ch[1010][1010];

int main(){
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch[i][j];
		}
	} 
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m;j++){
			if(ch[i][j]=='.'){
				sum++;
			}
		}
		if(sum==m) h[i]=1;
	}
	for(int j=1;j<=m;j++){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(ch[i][j]=='.'){
				sum++;
			}
		}
		if(sum==n) l[j]=1;
	}
	for(int i=1;i<=n;i++){
		if(h[i]==1) continue;
		for(int j=1;j<=m;j++){
			if(l[j]==1) continue;
			cout<<ch[i][j];
		}
		cout<<endl;
	}
	return 0;
}
